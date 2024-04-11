#include <bits/stdc++.h>
#define Task "D"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

const int N = 3030;

int n, m;
int sl[N];
vector <int> a[N];

int main() {
    ios_base::sync_with_stdio(0);
   // fi, fo;
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
    }
    long long res = 0;
    for(int i = 1; i <= n; i++) {
        memset(sl, 0, sizeof(sl));
        for(int j = 0; j < a[i].size(); j++) {
            int v = a[i][j];
            for(int k = 0; k < a[v].size(); k++)
                sl[a[v][k]]++;
        }
        for(int j = 1; j <= n; j++)
            if(sl[j] && j != i) res += 1ll * sl[j] * (sl[j] - 1) / 2;
    }
    cout << res;
    return 0;
}