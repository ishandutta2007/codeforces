#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int n, m;
int w[202020];
vector<int> v[202020];
int s;
int d[202020];

ll f[202020];
int g[202020];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        d[a]++;
        v[b].push_back(a);
        d[b]++;
    }
    cin >> s;
    vector<int> u;
    for (int i = 1; i <= n; i++) {
        if (d[i] == 1) u.push_back(i);
    }
    for (int k = 0; k < u.size(); k++) {
        if (u[k] == s) continue;
        g[u[k]] = 1;
        for (auto x : v[u[k]]) {
            if (g[x]) continue;
            d[x]--;
            f[x] = max(f[x],f[u[k]]+w[u[k]]);
            if (d[x] == 1) u.push_back(x);
        }
    }
    ll ww = 0;
    ll ff = 0;
    for (int i = 1; i <= n; i++) {
        if (g[i]) continue;
        ww += w[i];
        ff = max(ff,f[i]);
    }
    cout << ww+ff << "\n";
}