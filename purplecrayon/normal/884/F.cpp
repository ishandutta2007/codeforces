#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e2+10, MOD = 1e9+7;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
typedef pair<int, int> pii;
typedef vector<int> vi;

#include <bits/extc++.h>
const ll INF = numeric_limits<ll>::max() / 4;
typedef vector<ll> VL;
struct MCMF {
	int N;
	vector<vi> ed, red;
	vector<VL> cap, flow, cost;
	vi seen;
	VL dist, pi;
	vector<pii> par;

	MCMF(int N) :
		N(N), ed(N), red(N), cap(N, VL(N)), flow(cap), cost(cap),
		seen(N), dist(N), pi(N), par(N) {}

	void addEdge(int from, int to, ll cap, ll cost) {
		this->cap[from][to] = cap;
		this->cost[from][to] = cost;
		ed[from].push_back(to);
		red[to].push_back(from);
	}

	void path(int s) {
		fill(all(seen), 0);
		fill(all(dist), INF);
		dist[s] = 0; ll di;

		__gnu_pbds::priority_queue<pair<ll, int>> q;
		vector<decltype(q)::point_iterator> its(N);
		q.push({0, s});

		auto relax = [&](int i, ll cap, ll cost, int dir) {
			ll val = di - pi[i] + cost;
			if (cap && val < dist[i]) {
				dist[i] = val;
				par[i] = {s, dir};
				if (its[i] == q.end()) its[i] = q.push({-dist[i], i});
				else q.modify(its[i], {-dist[i], i});
			}
		};

		while (!q.empty()) {
			s = q.top().second; q.pop();
			seen[s] = 1; di = dist[s] + pi[s];
			for (int i : ed[s]) if (!seen[i])
				relax(i, cap[s][i] - flow[s][i], cost[s][i], 1);
			for (int i : red[s]) if (!seen[i])
				relax(i, flow[i][s], -cost[i][s], 0);
		}
		rep(i,0,N) pi[i] = min(pi[i] + dist[i], INF);
	}

	pair<ll, ll> maxflow(int s, int t) {
		ll totflow = 0, totcost = 0;
		while (path(s), seen[t]) {
			ll fl = INF;
			for (int p,r,x = t; tie(p,r) = par[x], x != s; x = p)
				fl = min(fl, r ? cap[p][x] - flow[p][x] : flow[x][p]);
			totflow += fl;
			for (int p,r,x = t; tie(p,r) = par[x], x != s; x = p)
				if (r) flow[p][x] += fl;
				else flow[x][p] -= fl;
		}
		rep(i,0,N) rep(j,0,N) totcost += cost[i][j] * flow[i][j];
		return {totflow, totcost};
	}

	// If some costs can be negative, call this before maxflow:
	void setpi(int s) { // (otherwise, leave this out)
		fill(all(pi), INF); pi[s] = 0;
		int it = N, ch = 1; ll v;
		while (ch-- && it--)
			rep(i,0,N) if (pi[i] != INF)
				for (int to : ed[i]) if (cap[i][to])
					if ((v = pi[i] + cost[i][to]) < pi[to])
						pi[to] = v, ch = 1;
		assert(it >= 0); // negative cost cycle
	}
};

int n, a[MAXN], cnt[26];
string s;

void solve(){
    cin >> n >> s;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cnt[s[i]-'a']++;

    //S, 26, n/2, T
    int N = n/2+26+2, S = n/2+26, T = n/2+26+1;
    MCMF flower(N);
    for (int i = 0; i < 26; i++) flower.addEdge(S, i, cnt[i], 0);
    for (int i = 0; i < n/2; i++) flower.addEdge(i+26, T, 2, 0);
    for (int i = 0; i < 26; i++) for (int j = 0; j < n/2; j++) {
        int cost = 0;
        int cnt = int(s[j]-'a' == i) + int(s[n-1-j]-'a' == i);
        if (cnt == 2) cost = -max(a[j], a[n-1-j]);
        else if (s[j]-'a' == i) cost = -a[j];
        else if (s[n-1-j]-'a' == i) cost = -a[n-1-j];
        else cost = 0;

        flower.addEdge(i, j+26, 1, cost);
    }
    flower.setpi(S);
    cout << -flower.maxflow(S, T).second << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}