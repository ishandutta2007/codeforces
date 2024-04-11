#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 2000 + 5;

int n, m, a[N][N];
string s[N];

int sum(int i, int j, int x) {
    i++; j++;
    return a[i][j] - a[i - x][j] - a[i][j - x] + a[i - x][j - x];
}

bool ok(int x1, int x2, int y1, int y2) {
    if (x1 == x2 and y1 == y2)
        return (s[x1][y1] == 'w');

    int x = x2 - x1 + 1;
    return sum(x2, y2, x) - sum(x2 - 1, y2 - 1, x - 2) == a[n][m];
}

void finish(int x1, int x2, int y1, int y2) {
    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++) {
            if (s[i][j] != 'w' and (i == x1 or i == x2 or j == y1 or j == y2))
                s[i][j] = '+';
        }
    }
    for (int i = 0; i < n; i++) cout << s[i] << "\n";
    exit(0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int j = 0; j < m; j++) {
            a[i + 1][j + 1] = (s[i][j] != '.');
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
        }
    }

    int mnr = N, mxr = -1;
    int mnc = N, mxc = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == 'w') {
                mnr = min(mnr, i);
                mxr = max(mxr, i);
                mnc = min(mnc, j);
                mxc = max(mxc, j);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == 'w' and i != mnr and i != mxr and j != mnc and j != mxc) {
                cout << "-1\n";
                return 0;
            }
        }
    }

    if (mxc - mnc == mxr - mnr) {
        finish(mnr, mxr, mnc, mxc);
    }

    int len = 1 + max(mxc - mnc, mxr - mnr);

    if (mxr - mnr > mxc - mnc) {
        for (int j = 0; j + len <= m; j++) {
            if (ok(mnr, mxr, j, j + len - 1)) {
                finish(mnr, mxr, j, j + len - 1);
            }
        }
    }
    else {
        for (int i = 0; i + len <= n; i++) {
            if (ok(i, i + len - 1, mnc, mxc)) {
                finish(i, i + len - 1, mnc, mxc);
            }
        }
    }
    cout << "-1\n";
    return 0;
}