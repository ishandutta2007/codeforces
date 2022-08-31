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
const int MAXN = 2e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 998244353, MAXK = 17, MAXA = 1e6+10, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const ll INF = 1e18+10;

struct DSU {
    int cc=0;
	vector<int> p, sz;
	void init(int n){ p.resize(n); sz.assign(n, 1); iota(p.begin(), p.end(), 0); cc=n; }
	int find_set(int v){ return v==p[v]?v:p[v]=find_set(p[v]); }
	bool union_sets(int a, int b){
		if ((a=find_set(a))==(b=find_set(b))) return false;
		if (sz[a] < sz[b]) swap(a, b);
		p[b]=a, sz[a]+=sz[b], sz[b]=0;
        cc--;
		return true;
	}
} d;

int n, m;
vector<ar<ll, 3>> ed;
set<int> adj[MAXN];

ll solve1(){
        set<int> unvis;
        for (int i = 0; i < n; i++) unvis.insert(i);
        for (int i = 0; i < m; i++) adj[ed[i][0]].insert(ed[i][1]), adj[ed[i][1]].insert(ed[i][0]);
        //modification of kruskals 

        d.init(n);
        for (int st = 0; st < n; st++) if (unvis.count(st)) {
            vector<int> q; q.reserve(n);
            q.push_back(st);
            unvis.erase(st);

            
            for (int rep = 0; rep < sz(q); rep++) {
                int c = q[rep];
                auto it = unvis.begin();
                while (it != unvis.end()) {
                    int nxt = *it;
                    if (adj[c].count(nxt)){ it = next(it); continue; }

                    d.union_sets(c, nxt);
                    it = next(it);
                    unvis.erase(prev(it));
                    q.push_back(nxt);
                }
            }
        }

        sort(ed.begin(), ed.end(), [&](auto a, auto b){ return a[2] < b[2]; });

        ll ans=0;
        for (int i = 0; i < m; i++) if (d.union_sets(ed[i][0], ed[i][1])) ans += ed[i][2];
        return ans;
}
void solve(){
    cin >> n >> m;
    ed.reserve(m);
    for (int i = 0; i < m; i++) {
        int a, b; ll w; cin >> a >> b >> w, --a, --b;
        ed.push_back({a, b, w});
    }
    ll cnt_z = ll(n)*ll(n-1)/2 - m;
    if (cnt_z > n-1) {
        cout << solve1() << '\n';
    } else {
        ll x=0;
        vector<ar<int, 2>> gone;
        vector<vector<bool>> ex(n, vector<bool>(n));
        for (auto& it : ed) x ^= it[2], ex[it[0]][it[1]] = ex[it[1]][it[0]] = 1;
        for (int i = 0; i < n; i++) for (int j = i+1; j < n; j++) if (!ex[i][j]) {
            gone.push_back({i, j});
        }

        d.init(n);
        ed.push_back({-1, -1, x});
        sort(ed.begin(), ed.end(), [&](auto a, auto b){ return a[2] < b[2]; });
        ll ans=INF;
        for (int i = 0; i < sz(gone); i++) {
            d.init(n);
            ll cur=0;
            for (int j = 0; j < sz(gone); j++) if (i != j) {
                d.union_sets(gone[j][0], gone[j][1]);
            }
            for (int j = 0; j < sz(ed); j++) {
                int a=ed[j][0], b=ed[j][1];
                ll w=ed[j][2];
                if (a == -1) {
                    assert(b == -1);
                    a = gone[i][0], b = gone[i][1];
                }
                if (d.union_sets(a, b)) cur += w;
            }
            assert(d.cc == 1);
            ans = min(ans, cur);
        }
        cout << ans << '\n';
    }
} 
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    //cin >> t_c;
    while (t_c--) solve();
}