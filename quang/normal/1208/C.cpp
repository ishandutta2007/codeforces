#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n;
int a[4][4] = {{8,9,1,13},
{3, 12, 7, 5},
{0, 2, 4, 11},
{6, 10, 15, 14}};

int res[N][N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int cur = 0;
    for (int i = 0; i < n; i += 4) {
        for (int j = 0; j < n; j += 4) {

            for (int ii = 0; ii < 4; ii++) {
                for (int jj = 0; jj < 4; jj++) {
                    res[i + ii][j + jj] = (cur << 4) | a[ii][jj];
                }
            }

            cur++;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << res[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}