#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

typedef unsigned long long ull;
typedef long long ll;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 500 + 5;

int n, a[N][N], x[N], d[N][N];
ll ans[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
        cin >> a[i][j];
        d[i][j] = a[i][j];
    }

    for (int i = 1; i <= n; i++)
        cin >> x[i];

    reverse(x + 1, x + n + 1);

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                d[x[i]][x[j]] = min(d[x[i]][x[j]], d[x[i]][x[k]] + d[x[k]][x[j]]);
                if (i <= k and j <= k)
                    ans[k] += d[x[i]][x[j]];
            }
        }
    }

    for (int i = n; i >= 1; i--) {
        cout << ans[i] << " ";
    }
    return 0;
}