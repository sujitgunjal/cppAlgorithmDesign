#include <iostream>
#include <vector>
#include <iomanip>
#include <limits.h>

using namespace std;


void gaussJordanElimination(vector<vector<double>>& augmentedMatrix) {
    int n = augmentedMatrix.size();

    for (int i = 0; i < n; ++i) {
        
        double piv = augmentedMatrix[i][i];
        for (int j = i; j < n + 1; ++j) {
            augmentedMatrix[i][j] /= piv;
        }

       
        for (int k = 0; k < n; ++k) {
            if (k != i) {
                double fact = augmentedMatrix[k][i];
                for (int j = i; j < n + 1; ++j) {
                    augmentedMatrix[k][j] -= fact * augmentedMatrix[i][j];
                }
            }
        }
    }
    return; 
}

int main() {
    
    int n;
    cin >> n;

 
    vector<vector<double>> augmentedMatrix(n, vector<double>(n + 1, 0.0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n + 1; ++j) {
            cin >> augmentedMatrix[i][j];
        }
    }

    
    gaussJordanElimination(augmentedMatrix);

    
    bool solvable = true;
    for (int i = 0; i < n; ++i) {
        if (augmentedMatrix[i][i] == 0) {
            solvable = false;
            break;
        }
    }

    if (solvable) {
        cout << "YES" << endl;
        for (int i = 0; i < n; ++i) {
            cout << fixed << setprecision(2) << augmentedMatrix[i][n] << " ";
        }
    } else {
        cout << "NO";
    }

    
    return 0;
}
