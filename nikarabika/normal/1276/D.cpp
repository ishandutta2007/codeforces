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

const int maxn = 200 * 1001;
const LL Mod = 998244353;
vector<pii> adj[maxn];
LL dp[maxn],
   pd[maxn],
   dd[maxn],
   n;

LL choose_par(vector<pii>::iterator vec, int n) {
    vector<LL> pidp;
    pidp.reserve(n + 1);
    pidp.PB(1);
    for (int i = 0; i < n; i++) {
        auto e = vec[i];
        pidp.PB(pidp.back() * dp[e.R] % Mod);
    }
    LL pipd = 1;
    LL ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        auto e = vec[i];
        ans = (ans + (pipd * pidp[i] % Mod) * dd[e.R] % Mod) % Mod;
        pipd = pipd * pd[e.R] % Mod;
    }
    return ans;
}

void dfs(int u, int p = -1) {
    for (auto e: adj[u])
        if (e.R != p)
            dfs(e.R, u);
    sort(all(adj[u]));
    int mid = 0;
    for (int i = 0; i < sz(adj[u]); i++)
        if (adj[u][i].R == p) {
            adj[u].erase(adj[u].begin() + i);
            mid = i;
            break;
        }
    if (sz(adj[u]) == 0) {
        dp[u] = pd[u] = dd[u] = 1;
        return;
    }
    LL pidpvl = 1;
    for (int i = 0; i < mid; i++)
        pidpvl = pidpvl * dp[adj[u][i].R] % Mod;
    LL pipdvr = 1;
    LL pidpvr = 1;
    for (int i = mid; i < sz(adj[u]); i++) {
        pipdvr = pipdvr * pd[adj[u][i].R] % Mod;
        pidpvr = pidpvr * dp[adj[u][i].R] % Mod;
    }
    LL lechoose = choose_par(adj[u].begin(), mid);
    LL richoose = choose_par(adj[u].begin() + mid, sz(adj[u]) - mid);

    dp[u] = (pidpvl + lechoose) * pipdvr % Mod;
    dd[u] = pidpvl * (pidpvr + richoose) % Mod;
    pd[u] = (pidpvl * pidpvr % Mod) + (lechoose * pipdvr + pidpvl * richoose) % Mod;
    pd[u] %= Mod;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int fi, se;
        cin >> fi >> se;
        fi--, se--;
        adj[fi].PB(MP(i, se));
        adj[se].PB(MP(i, fi));
    }
    dfs(0);
    cout << pd[0] << '\n';
	return 0;
}