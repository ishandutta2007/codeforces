#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int a[200][200] = {};

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
    int n; cin >> n;
    int k; cin >> k;
    if (k > n * n) {
        cout << -1;
    } else {
        int row = 0;
        while (k) {
            if ((2 * (n - row) - 1) <= k) {
                for (int i = row; i < n; ++i) {
                    a[row][i] = 1;
                    a[i][row] = 1;
                } 
                k -= (2 * (n - row) - 1);
                row++;
            } else if(k & 1) {
                a[row][row] = 1;
                k--;
                for (int i = 0; i < (k / 2); ++i) {
                    a[row][i + row + 1] = 1;
                    a[i + row + 1][row] = 1;
                }
                k = 0;
            } else {
                if (row < n - 1) {
                    a[row + 1][row + 1] = 1;
                    k--;
                } else {
                    for (int i = 0; i < (k / 2); ++i) {
                        a[row][i + row + 1] = 1;
                        a[i + row + 1][row] = 1;
                    }
                    k = 0;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << a[i][j] << " ";
            }
            cout << "\n";
        }
    }
}