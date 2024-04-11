//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

int par[100];

int root(int u) {
    return par[u] < 0 ? u : par[u] = root(par[u]);
}

bool merge(int u, int v) {
    if ((u = root(u)) == (v = root(v)))
        return false;
    if (par[u] > par[v])
        swap(u, v);
    par[u] += par[v];
    par[v] = u;
    return true;
}

int solve() {
    memset(par, -1, sizeof par);
    int n;
    int ans = 0;
    string s, t;
    cin >> n;
    cin >> s >> t;
    for (int i = 0; i < n; i++)
        if (s[i] > t[i])
            return cout << -1 << endl, 0;
        else
            ans += merge(s[i] - 'a', t[i] - 'a');
    cout << ans << endl;
    return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int q;
	cin >> q;
	while (q--)
		solve();
	return 0;
}