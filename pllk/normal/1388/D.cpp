#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int n;
ll a[202020];
int b[202020];
vector<int> v[202020];
vector<int> w[202020];

ll s[202020];
int d[202020];

void dfs(int x) {
    s[x] = a[x];
    for (auto u : v[x]) {
        dfs(u);
        if (s[u] >= 0) {
            s[x] += s[u];
            w[u].push_back(x);
        } else {
            w[x].push_back(u);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) {
        if (b[i] != -1) v[b[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        if (b[i] == -1) {
            dfs(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (auto u : w[i]) d[u]++;
    }
    vector<int> f;
    for (int i = 1; i <= n; i++) {
        if (d[i] == 0) f.push_back(i);
    }
    ll r = 0;
    for (int i = 0; i < n; i++) {
        r += a[f[i]];
        if (b[f[i]] != -1) a[b[f[i]]] += a[f[i]];
        for (auto u : w[f[i]]) {
            d[u]--;
            if (d[u] == 0) f.push_back(u);
        }
    }
    cout << r << "\n";
    for (int i = 0; i < n; i++) cout << f[i] << " ";
    cout << "\n";
}