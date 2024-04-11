#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MAXN = 30;
int arr[MAXN][MAXN];
int mn[MAXN][MAXN], mx[MAXN][MAXN];

main() {
    int n;
    cin >> n;
    for (int i = n - 2; i >= 0; --i) {
        arr[i][0] = 0;
        for (int j = 1; j < n; ++j) {
            arr[i][j] = mx[i + 1][j - 1] - mn[i + 1][j] + 1;
        }
        for (int j = n - 1; j >= 0; --j) {
            mx[i][j] = mx[i + 1][j];
            mn[i][j] = mn[i + 1][j];
            if (j != n - 1) {
                mx[i][j] = max(mx[i][j], mx[i][j + 1]);
                mn[i][j] = min(mn[i][j], mn[i][j + 1]);
            }
            mx[i][j] += arr[i][j];
            mn[i][j] += arr[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    int q;
    cin >> q;
    while (q--) {
        int sum;
        cin >> sum;
        int i = 0, j = 0;
        while (i != n - 1 || j != n - 1) {
            cout << i + 1 << " " << j + 1 << endl;
            sum -= arr[i][j];
            if (i == n - 1) {
                j++;
                continue;
            }
            if (j == n - 1) {
                i++;
                continue;
            }
            if (sum > mx[i + 1][j]) {
                j++;
            } else {
                i++;
            }
        }
        cout << n << " " << n << endl;
    }
    return 0;
}