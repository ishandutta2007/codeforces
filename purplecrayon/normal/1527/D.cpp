#include "bits/stdc++.h"
using namespace std;

template<class T> using min_pq=priority_queue<T, vector<T>, greater<T>>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rnd(int l, int r){
	return uniform_int_distribution<int>(l, r)(rng);
}

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 3e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};


int n, depth[MAXN], anc[MAXN][MAXL];
vector<int> adj[MAXN];

void init_lca(int c=0, int p=-1, int d=0){
	depth[c]=d, anc[c][0]=p;
	for (int i=1; i < MAXL; i++) anc[c][i] = (anc[c][i-1]==-1?-1:anc[anc[c][i-1]][i-1]);
	for (auto nxt : adj[c]) if (nxt != p) init_lca(nxt, c, d+1);
}
int jmp(int a, int h){
	for (int i = 0; i < MAXL; i++) if ((h>>i)&1) a = anc[a][i];
	return a;
}
int lca(int a, int b){
	if (depth[a] < depth[b]) swap(a, b);
	a = jmp(a, depth[a]-depth[b]);
	if (a==b) return a;
	for (int i = MAXL-1; i >= 0; i--){
		if (anc[a][i] != anc[b][i]) a = anc[a][i], b = anc[b][i];
	}
	assert(anc[a][0]==anc[b][0]);
	return anc[a][0];
}
int dist(int a, int b){ return depth[a]+depth[b]-2*depth[lca(a, b)]; }

int sub[MAXN], p[MAXN];
ll a[MAXN], ans=0;

int dfs1(int c=0, int p=-1) {
    sub[c]=1;
    for (auto& nxt : adj[c]) if (nxt != p) sub[c] += dfs1(nxt, c);
    return sub[c];
}
void solve(){
    cin >> n;
    for (int i = 0; i < n; i++) {
        a[i] = p[i] = i;
    }
    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b), adj[b].push_back(a);
    }
    init_lca(); 
    dfs1();
    sort(p, p+n, [&](int i, int j) {
        return a[i] < a[j];
    });

    ans = 0;

    vector<ll> tot(n+1);
    ar<int, 2> diam; diam.fill(-1);
    for (int i = 0; i < n; i++) {
        int c=p[i];
        if (a[c] != i) break;

        ll pans = ans;
        if (i) {
            bool bad=1;
            for (ar<int, 3> nd : {ar<int, 3>{diam[0], diam[1], c}, ar<int, 3>{diam[0], c, diam[1]}, ar<int, 3>{diam[1], c, diam[0]}}) {
                if (dist(nd[0], nd[1]) == dist(nd[0], nd[2])+dist(nd[1], nd[2])) {
                    diam = {nd[0], nd[1]};
                    bad=0;
                    break;
                }
            }
            if (bad) break;

            int l=lca(diam[0], diam[1]);
            if (diam[1] == l) swap(diam[0], diam[1]);
            if (diam[0] == l) {
                ans += ((ll)sub[diam[1]])*((ll)n-sub[jmp(diam[1], depth[diam[1]]-depth[diam[0]]-1)]);
            } else {
                ans += ((ll)sub[diam[0]])*((ll)sub[diam[1]]);
            }
        } else {
            diam = {c, c};
            ans += ((ll)n-sub[c])*((ll)sub[c]-1);
            for (auto nxt : adj[c]) if (nxt != anc[c][0]) {
                ans += ((ll)sub[nxt])*((ll)n-sub[nxt]-1);
            }
            ans /= 2;
            ans += n-1;
        }
        ll cans = ans - pans;
        tot[i+1] = cans;
    }

    tot[0] = (ll(n)*(ll(n-1)))/2 - tot[1];
    for (int i = 1; i < n; i++) tot[i] -= tot[i+1];
    for (int i = 0; i <= n; i++) cout << tot[i] << ' '; cout << '\n';

    for (int i = 0; i < n; i++) adj[i].clear();
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}