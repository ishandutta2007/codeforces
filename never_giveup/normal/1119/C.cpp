#include <bits/stdc++.h>
#define fr first
#define sc second
#define m_p make_pair
using namespace std;

typedef long long ll;

const ll llinf = 1e18;

const int maxn = 505, inf = 1e9 + 100;

int a[2][maxn][maxn];

int main() {
    #ifdef ONPC
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    #endif // ONPC
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int t = 0; t < 2; t++) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> a[t][i][j];
        for (int i = 1; i < n; i++)
            for (int j = 1; j < m; j++)
                if (a[t][i][j]) {
                    a[t][0][j] ^= 1;
                    a[t][i][0] ^= 1;
                    a[t][0][0] ^= 1;
                    a[t][i][j] ^= 1;
                }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
    if (a[0][i][j] != a[1][i][j]) {
        cout << "No";
        return 0;
    }
    cout << "Yes";
}