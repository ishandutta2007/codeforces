
// Problem: B. Button Lock
// Contest: Codeforces - 2020-2021 ICPC, NERC, Northern Eurasia Onsite (Unrated, Online Mirror, ICPC Rules, Teams Preferred)
// URL: https://codeforces.com/contest/1510/problem/B
// Memory Limit: 512 MB
// Time Limit: 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/priority_queue.hpp> // Common file
// #include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
// using namespace __gnu_pbds;

// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// ordered_set;	

struct splitmix64_hash {
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}
 
	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};
 
template <typename K, typename V, typename Hash = splitmix64_hash>
using hash_map = __gnu_pbds::gp_hash_table<K, V, Hash>;
 
template <typename K, typename Hash = splitmix64_hash>
using hash_set = hash_map<K, __gnu_pbds::null_type, Hash>;

template<class A,class B>auto&operator<<(ostream&o,pair<A,B>p){return o<<'('<<p.first<<", "<<p.second<<')';}
template<class T>auto operator<<(ostream&o,T x)->decltype(x.end(),o){o<<'{';int i=0;for(auto e:x)o<<", "+2*!i++<<e;return o<<'}';}
#ifdef DEBUG
#define debug(x...) cerr<<"["#x"]: ",[](auto...a){((cerr<<a<<"; "),...);}(x),cerr<<'\n'
#else
#define debug(...) {}
#endif

#define FOR(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for(int i = (a); i >= (b); --i)
#define RI(i,n) FOR(i,1,(n))
#define REP(i,n) FOR(i,0,(n)-1)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#define pb push_back
#define st first
#define nd second
#define sz(w) (int) w.size()
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pii, int> para;
const ll inf = 1e18 + 7;
const ll maxN = 1e6 + 5;
const ll MOD = 1e9 + 7;

const ll INF = numeric_limits<ll>::max() / 4;
typedef vector<ll> VL;
#define all(x) begin(x), end(x)

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
		REP(i,N) pi[i] = min(pi[i] + dist[i], INF);
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
		REP(i,N) REP(j,N) totcost += cost[i][j] * flow[i][j];
		return {totflow, totcost};
	}

	// If some costs can be negative, call this before maxflow:
	void setpi(int s) { // (otherwise, leave this out)
		fill(all(pi), INF); pi[s] = 0;
		int it = N, ch = 1; ll v;
		while (ch-- && it--)
			REP(i,N) if (pi[i] != INF)
				for (int to : ed[i]) if (cap[i][to])
					if ((v = pi[i] + cost[i][to]) < pi[to])
						pi[to] = v, ch = 1;
		assert(it >= 0); // negative cost cycle
	}
};

int from_bin(string& s, int d) {
	int ans = 0;
	REP(i, d) {
		if (s[i] == '1') ans += (1 << (d - i - 1));
	}
	return ans;
}

bool is_subset(string& s1, string &s2, int d) {
	REP(i, d) {
		if (s1[i] == '1' && s2[i] == '0') {
			return false;
		}
	}
	return true;
}

vi get_diff(string& s1, string& s2, int d) {
	vi ans;
	REP(i, d) {
		if (s1[i] == '0' && s2[i] == '1') {
			ans.pb(i);
		}
	}
	return ans;
}

string s[maxN];
int num[maxN];
map<int, string> val;

// sprawdz MODULO!
int main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int d, n; cin >> d >> n;
	REP(i, n) {
		cin >> s[i];
		num[i] = from_bin(s[i], d);
		val[num[i]] = s[i];
	}
	string tmp = "";
	REP(_, d) tmp += "0";
	val[0] = tmp;
	MCMF mcmf((1 << (d + 1)) + 1);
	REP(i, n) {
		REP(j, n) {
			if (i == j) continue;
			if (is_subset(s[i], s[j], d)) {
				// debug(num[i], (1 << d) + num[j]);
				mcmf.addEdge(num[i], (1 << d) + num[j], 1, __builtin_popcount(num[j]) - __builtin_popcount(num[i]));
			}
		}
		mcmf.addEdge(num[i], (1 << (d + 1)), 1, 2e6);
		// mcmf.addEdge(num[i] + (1 << d), num[i], 1, -1e6);
		// debug(0, num[i]);
		// debug((1 << d) + num[i], 1 << (d + 1));
		mcmf.addEdge(0, num[i], 1, __builtin_popcount(num[i]) + 1);
		mcmf.addEdge((1 << d) + num[i], 1 << (d + 1), 1, 0);
	}
	pll ans = mcmf.maxflow(0, 1 << (d + 1));
	// debug(ans);
	int ile = 0;
	// debug(mcmf.flow);
	vector<vi> tmp2;
	vector<bool> used(1 << (d + 1));
	while (true) {
		int st = 0;
		bool b = true;
		vi foo;
		while (b) {
			b = false;
			// debug(st, foo);
			REP(i, 1 << (d + 1)) {
				if (mcmf.flow[st][i] && !used[i]) {
					mcmf.flow[st][i] = 0;
					used[i] = true;
					if (i >= (1 << d)) i -= (1 << d);
					used[i] = true;
					for (auto x: get_diff(val[st], val[i], d)) {
						foo.pb(x);
						ile++;
					}
					b = true;
					st = i; 
					break;
				}
			}
		}
		if (st == 0) break;
		tmp2.pb(foo);
		// cout << "R ";
	}
	// debug(tmp2);
	cout << ile + sz(tmp2) - 1 << "\n";
	REP(i, sz(tmp2)) {
		for (auto x: tmp2[i]) cout << x << " ";
		if (i != sz(tmp2) - 1) cout << "R ";
	}
	// __gnu_pbds::priority_queue<int> q;
	return 0;
}