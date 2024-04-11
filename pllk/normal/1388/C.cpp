#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int n, m;
ll p[202020];
ll h[202020];

vector<int> v[202020];
ll c[202020];
bool ok;

ll dfs(int s, int e) {
    c[s] = p[s];
    ll z = 0;
    for (auto u : v[s]) {
        if (u == e) continue;
        z += dfs(u,s);
        c[s] += c[u];
    }
    if ((c[s]+h[s])%2 != 0) ok = false;
    ll a = (c[s]+h[s])/2;
    ll b = (c[s]-h[s])/2;
    if (a < 0 || a > c[s] || b < 0 || b > c[s]) ok = false;
    if (a+b != c[s] || b > z+p[s]) ok = false;
    return b;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) cin >> p[i];
        for (int i = 1; i <= n; i++) cin >> h[i];
        for (int i = 1; i <= n; i++) v[i].clear();
        for (int i = 1; i <= n; i++) c[i] = 0;
        for (int i = 1; i <= n-1; i++) {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        ok = true;
        dfs(1,0);
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
}