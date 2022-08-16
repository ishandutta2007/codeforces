#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[3][3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> a[i][j];
        }
    }

    vector<vector<int>> b(3, vector<int>(3));

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (a[i][j] % 2 == 1) {
                b[i][j] += a[i][j];
                if (i-1 >= 0)
                    b[i-1][j] += a[i][j];
                if (i+1 < 3)
                    b[i+1][j] += a[i][j];
                if (j-1 >= 0)
                    b[i][j-1] += a[i][j];
                if (j+1 < 3)
                    b[i][j+1] += a[i][j];
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (b[i][j] % 2 == 0)
                cout << 1;
            else
                cout << 0;
        }
        cout << "\n";
    }
    return 0;
}