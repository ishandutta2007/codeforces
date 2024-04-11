#include <iostream>
#include <vector>

using namespace std;

int n, k;
int lot[100][100];
vector<vector<int>> moves;

int count;

void check() {
    for (int j = 1; j <= n; j++) {
        if (lot[2][j] && lot[1][j] == lot[2][j]) {
            moves.push_back({lot[2][j],1,j});
            lot[2][j] = 0;
            count++;
        }
        if (lot[3][j] && lot[3][j] == lot[4][j]) {
            moves.push_back({lot[3][j],4,j});
            lot[3][j] = 0;
            count++;
        }
    }
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= n; j++) cin >> lot[i][j];
    }
    while (count < k) {
        check();
        if (k == 2*n && count == 0) break;
        if (lot[2][n] && !lot[3][n]) {
            moves.push_back({lot[2][n],3,n});
            swap(lot[2][n],lot[3][n]);
        }
        check();
        for (int j = n; j >= 2; j--) {
            if (!lot[2][j] && lot[2][j-1]) {
                moves.push_back({lot[2][j-1],2,j});
                swap(lot[2][j-1],lot[2][j]);
            }
        }
        check();
        for (int j = 1; j <= n-1; j++) {
            if (!lot[3][j] && lot[3][j+1]) {
                moves.push_back({lot[3][j+1],3,j});
                swap(lot[3][j],lot[3][j+1]);
            }
        }
        check();
        if (lot[3][1] && !lot[2][1]) {
            moves.push_back({lot[3][1],2,1});
            swap(lot[2][1],lot[3][1]);
        }
    }
    if (count == k) {
        cout << moves.size() << "\n";
        for (auto x : moves) {
            cout << x[0] << " " << x[1] << " " << x[2] << "\n";
        }
    } else {
        cout << "-1\n";
    }
}