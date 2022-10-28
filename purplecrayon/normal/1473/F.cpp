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
const int MAXN = 3e3+10, MAXM = 5e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 110, INF = 1e9+10, MAXA = 1e2+10, MAXB = 24, MAXBB = (1<<MAXB), MOD2=MOD-1;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
struct PushRelabel {
	struct Edge {
		int dest, back;
		ll f, c;
	};
	vector<vector<Edge>> g;
	vector<ll> ec;
	vector<Edge*> cur;
	vector<vi> hs; vi H;
	PushRelabel(int n) : g(n), ec(n), cur(n), hs(2*n), H(n) {}

	void addEdge(int s, int t, ll cap, ll rcap=0) {
		if (s == t) return;
		g[s].push_back({t, sz(g[t]), 0, cap});
		g[t].push_back({s, sz(g[s])-1, 0, rcap});
	}

	void addFlow(Edge& e, ll f) {
		Edge &back = g[e.dest][e.back];
		if (!ec[e.dest] && f) hs[H[e.dest]].push_back(e.dest);
		e.f += f; e.c -= f; ec[e.dest] += f;
		back.f -= f; back.c += f; ec[back.dest] -= f;
	}
	ll calc(int s, int t) {
		int v = sz(g); H[s] = v; ec[t] = 1;
		vi co(2*v); co[0] = v-1;
		rep(i,0,v) cur[i] = g[i].data();
		for (Edge& e : g[s]) addFlow(e, e.c);

		for (int hi = 0;;) {
			while (hs[hi].empty()) if (!hi--) return -ec[s];
			int u = hs[hi].back(); hs[hi].pop_back();
			while (ec[u] > 0)  // discharge u
				if (cur[u] == g[u].data() + sz(g[u])) {
					H[u] = 1e9;
					for (Edge& e : g[u]) if (e.c && H[u] > H[e.dest]+1)
						H[u] = H[e.dest]+1, cur[u] = &e;
					if (++co[H[u]], !--co[hi] && hi < v)
						rep(i,0,v) if (hi < H[i] && H[i] < v)
							--co[H[i]], H[i] = v + 1;
					hi = H[u];
				} else if (cur[u]->c && H[u] == H[cur[u]->dest]+1)
					addFlow(*cur[u], min(ec[u], cur[u]->c));
				else ++cur[u];
		}
	}
	bool leftOfMinCut(int a) { return H[a] >= sz(g); }
};

int prv[MAXA];
vector<int> di[MAXA];

void solve(){

    //add edges of INF cost from one number to each of it's divisors
    //negate all the numbers, now want to find the min cost of a strange set
    //
    //if it's negative, add edge of |a| from s to a
    //otherwise add edge of |a| from a to t
    //
    //now how to reduce the memory
    //just add the edge to the nearest thing that is a divisor

    for (int i = 1; i < MAXA; i++) for (int j = i; j < MAXA; j+=i) di[j].push_back(i);
    int n; scanf("%d",&n);
    vector<int> a(n); for (auto& it : a) scanf("%d",&it);
    vector<ll> b(n); for (auto& it : b) scanf("%lld",&it), it *= -1;

    const int S = n, T = n+1;
    PushRelabel flower(n+2);

    memset(prv, -1, sizeof(prv));
    for (int i = 0; i < n; i++){
        for (int j : di[a[i]]) if (prv[j] != -1){
            flower.addEdge(i, prv[j], INF);
        }
        prv[a[i]] = i;
    }
    for (int i = 0; i < n; i++){
        if (b[i] < 0) flower.addEdge(S, i, -b[i]);
        else flower.addEdge(i, T, b[i]);
    }
    flower.calc(S, T);
    ll ans=0;
    for (int i = 0; i < n; i++) if (flower.leftOfMinCut(i)) ans += b[i];
    cout << -ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    //cin >> t_c;
    while (t_c--) solve();
}