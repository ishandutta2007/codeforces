#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e3+10, MOD = 1e9+7;
const ll INF =  1e15+10; 

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
typedef pair<int, int> pii;
typedef vector<int> vi;

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


int color(int x, int y) {
    if (x%2 == 0 && y%2 == 0) return 1;
    if ((x-1)%2 == 0 && y%2 == 0) return 0;
    if (x%2 == 0 && (y-1)%2 == 0) return 2;
    if ((x-1)%2 == 0 && (y-1)%2 == 0) return 3;
    assert(false);
    return -1;
}

int n, col[MAXN];
ar<int, 3> a[MAXN];

void solve() {
    cin >> n;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
        col[i] = color(a[i][0], a[i][1]);
        ans += a[i][2];
    }
    const int N = 2*n+2, S = 2*n, T = 2*n+1;
    PushRelabel flower(N);
    for (int i = 0; i < n; i++) {
        flower.addEdge(2*i, 2*i+1, a[i][2]);
    }
    for (int i = 0; i < n; i++) {
        if (col[i] == 0) {
            flower.addEdge(S, 2*i, INF);
        }
        if (col[i] == 3) {
            flower.addEdge(2*i+1, T, INF);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (col[i]+1 == col[j] && abs(a[i][0]-a[j][0]) <= 1 && abs(a[i][1]-a[j][1]) <= 1) {
                flower.addEdge(2*i+1, 2*j, INF);
            }
        }
    }
    cout << ans - flower.calc(S, T) << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}