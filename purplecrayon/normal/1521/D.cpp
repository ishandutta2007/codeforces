#include "bits/stdc++.h"
using namespace std;

template<class T> using min_pq=priority_queue<T, vector<T>, greater<T>>;

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 1e5+10, MAXM = 3e5+10, MAXL = 20, ALP = 20, MOD = 998244353, MAXK = 17, INF = 1e9+10, MAXA = 1e2+10, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

struct DSU {
	vector<int> p, sz;
	void init(int n){ p.resize(n); sz.assign(n, 1); iota(p.begin(), p.end(), 0); }
	int find_set(int v){ return v==p[v]?v:p[v]=find_set(p[v]); }
	bool union_sets(int a, int b){
		if ((a=find_set(a))==(b=find_set(b))) return false;
		if (sz[a] < sz[b]) swap(a, b);
		p[b]=a, sz[a]+=sz[b], sz[b]=0;
		return true;
	}
} d;

int n;
vector<int> adj[MAXN];
int dp[MAXN][2]; //there's a path ending at node c, or there isn't
ll bld[MAXN][2]; //bld back the dp


bool smin(int& a, int b) {
    bool ans = a > b;
    a = min(a, b);
    return ans;
}
void dfs(int c=0, int p=-1) {
    dp[c][0] = dp[c][1] = INF;
    if (p != -1)
        adj[c].erase(find(adj[c].begin(), adj[c].end(), p));
    for (auto nxt : adj[c]) 
        dfs(nxt, c);

    {
        //if there's a path ending at node c, either a new thing starts here or i extend exactly one vertical path
        int cur = 0;
        for (auto nxt : adj[c]) {
            cur += dp[nxt][0];
        }
        if (smin(dp[c][1], cur)) {
            bld[c][1] = -1;
        }
        for (auto nxt : adj[c]) {
            int ncur = cur;
            ncur -= dp[nxt][0];
            ncur += dp[nxt][1];
            
            if (smin(dp[c][1], ncur)) {
                bld[c][1] = nxt;
            }
        }
    }
    if (sz(adj[c]) >= 2) {
        //if there's no path ending at node c, you pair exactly two paths
        int cur = 0;
        for (auto nxt : adj[c]) 
            cur += dp[nxt][0];
        //-dp[path_1][0] - dp[path_2][0] + dp[path_1][1] + dp[path_1][1] + 1
        vector<ar<int, 2>> val; val.reserve(sz(adj[c]));
        for (auto nxt : adj[c]) {
            val.push_back({-dp[nxt][0] + dp[nxt][1], nxt});
        }
        sort(val.begin(), val.end());
        dp[c][0] = min(dp[c][0], cur+val[0][0]+val[1][0]+1);
        bld[c][0] = ll(val[0][1])*n+val[1][1];
    }

    if (smin(dp[c][0], 1+dp[c][1])) {
        bld[c][0] = -1;
    }
}
vector<ar<int, 2>> to_rem;
void rec(int c=0, int p=-1, int col=0) {
    if (!col && bld[c][0] == -1) { rec(c, p, 1); return; } //i'm just cutting the parent edge
    if (col) {
        for (auto nxt : adj[c]) {
            if (nxt != bld[c][1]) {
                to_rem.push_back({c, nxt});
                rec(nxt, c, 0);
            } else {
                rec(nxt, c, 1);
            }
            
        }
    } else {
        int a = bld[c][0]/n, b = bld[c][0]%n;
        for (auto nxt : adj[c]) {
            if (nxt != a && nxt != b) {
                to_rem.push_back({c, nxt});
                rec(nxt, c, 0);
            } else {
                rec(nxt, c, 1);
            }
        }
    }
}
void solve(){
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b, --a, --b;
        adj[a].push_back(b), adj[b].push_back(a);
    }

    dfs();
    cout << dp[0][0]-1 << '\n';
    rec();

    assert(sz(to_rem) == dp[0][0]-1);

    set<ar<int, 2>> s;
    for (auto it : to_rem) s.insert(it);

    d.init(n);
    vector<int> deg(n);
    for (int i = 0; i < n; i++) for (auto nxt : adj[i]) if (!s.count({i, nxt}) && !s.count({nxt, i})) {
        d.union_sets(i, nxt), deg[i]++, deg[nxt]++;
    }

    map<int, vector<int>> comp;
    for (int i = 0; i < n; i++) if (deg[i] <= 1) {
        comp[d.find_set(i)].push_back(i);
    }
    assert(sz(comp) == dp[0][0]);
    vector<ar<int, 2>> to_ad;

    vector<vector<int>> mp; 
    for (auto it : comp) { 
        while (sz(it.second) < 2) it.second.push_back(it.second.back());
        mp.push_back(it.second);
    }

    for (int i = 1; i < sz(mp); i++) {
        to_ad.push_back({mp[i-1][1], mp[i][0]});
    }

    assert(sz(to_ad) == sz(to_rem));
    for (int i = 0; i < sz(to_ad); i++) {
        cout << to_rem[i][0]+1 << ' ' << to_rem[i][1]+1 << ' ' << to_ad[i][0]+1 << ' ' << to_ad[i][1]+1 << '\n';
    }

    for (int i = 0; i < n; i++)
        adj[i].clear();
    to_rem.clear();

}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    cin >> t_c;
    while (t_c--) solve();
}