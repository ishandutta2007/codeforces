#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ull = unsigned long long;
using ll = long long;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 501;

int n, m, a[N][N], b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    int q; cin >> q;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    for (int i = 0; i < n; i++) {
        int cur = 0, best = 0;
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 1)
                cur += 1;
            else cur = 0;

            best = max(best, cur);
        }
        b[i] = best;
    }

    while (q--) {
        int i, j;
        cin >> i >> j; --i; --j;

        a[i][j] = 1 - a[i][j];
        int cur = 0, best = 0;
        for (int k = 0; k < m; k++) {
            if (a[i][k] == 1)
                cur += 1;
            else cur = 0;

            best = max(best, cur);
        }
        b[i] = best;

        cout << *max_element(b, b + n) << "\n";
    }
    return 0;
}