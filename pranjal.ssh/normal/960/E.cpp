#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define FOR(i,a,b) for (auto i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(auto i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
typedef long long ll; typedef pair <int, int> ii; typedef vector <int> vi; const int inf = 1e9 + 7;
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class T> void dbs(string str, T t) {cout << str << " : " << t << endl;}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cout << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void prc(T a, T b) {cout << "["; for (T i = a; i != b; ++i) {if (i != a) cout << ", "; cout << *i;} cout << "]";cout<<endl;}


vector<vi> g;
vector<ll> w;
vi odd, even;
ll ans;
vi s;
int n;
inline ll add(ll x, ll y) {
	return (x + y) % inf;
}
inline ll sub(ll x, ll y) {
	return add(add(x, -y), inf);
}
inline ll mul(ll x, ll y) {
	return (x * y) % inf;
}
void dfs(int u, int p) {
	odd[u] = 1;
	s[u] = 1;
	ans = add(ans, mul(w[u], mul(1, n)));
	for (int v : g[u]) if (v != p) {
		dfs(v, u);
		s[u] += s[v];
		ans = sub(ans, mul(w[u], mul(odd[v], n - s[v])));
		ans = add(ans, mul(w[u], mul(even[v], n - s[v])));
		odd[u] += even[v];
		even[u] += odd[v];
	}
}

void dfs2(int u, int p) {
	int o = odd[u], e = even[u];
	
	if (u) {
		odd[u] += even[p] - o;
		even[u] += odd[p] - e;
		// pr(u, even[p] - o, odd[p] - e);
		ans = add(ans, mul(w[u], mul(even[p] - o, s[u])));
		ans = sub(ans, mul(w[u], mul(odd[p] - e, s[u])));
	}

	for (int v : g[u]) if (v != p) {
		dfs2(v, u);
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	g.resize(n), w.resize(n);
	FOR (i, 0, n - 1) {
		cin >> w[i];
		if (w[i] < 0) w[i] += inf;
	}
	odd.resize(n), even.resize(n), s.resize(n);

	FOR (i, 0, n - 2) {
		int u, v; cin >> u >> v;
		--u, --v;
		g[u].push_back(v), g[v].push_back(u);
	}
	// return 0;
	dfs(0, -1);
	dfs2(0, -1);
	// pr(even, odd);
	FOR (i, 0, n - 1) assert(even[i] + odd[i] == n);
	cout << ans << "\n";

	return 0;
}