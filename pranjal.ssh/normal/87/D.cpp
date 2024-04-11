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


const int N = 1e5+10;
int p[N], r[N], sub[N], vis[N];
ii e[N];
ll ans[N];
vector<vector<ii>> g;
int get(int x) {
	return x == p[x] ? x : p[x] = get(p[x]);
}
void connect(int x, int y) {
	x = get(x), y = get(y);
	if (x == y) return;
	if (r[x] > r[y]) swap(x, y);
	p[x] = y;
	r[y] += r[x];
}
void dfs(int u, int par, int no) {
	vis[u] = 1;
	for (auto v : g[u]) if (v.F != par) {
		dfs(v.F, u, no);
		sub[u] += sub[v.F];
		ans[v.S] = sub[v.F] * 1LL * (no - sub[v.F]);
	}
}
int get_sum(int u, int par) {
	int sum = sub[u];
	for (auto v : g[u]) if (v.F != par) {
		sum += get_sum(v.F, u);
	}
	return sum;
}
#define get_id(x) (lower_bound(all(id), x) - id.begin())
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	map<int, vi> mp;
	iota(p, p+N, 0);
	fill(r, r+N, 1);
	FOR (i, 1, n - 1) {
		int x, y, z; cin >> x >> y >> z;
		e[i] = {x, y};
		mp[z].push_back(i);
	}


	for (auto it : mp) {
		vi id; for (int x : it.S) id.push_back(e[x].F = get(e[x].F)), id.push_back(e[x].S = get(e[x].S));

		sort(all(id)); id.resize(unique(all(id)) - id.begin());
		int no = sz(id);
		g.clear(); g.resize(no);
		FOR (i, 0, no - 1) sub[i] = r[id[i]];
		for (int x : it.S) {
			g[get_id(e[x].F)].emplace_back(get_id(e[x].S), x);
			g[get_id(e[x].S)].emplace_back(get_id(e[x].F), x);
		}
		fill(vis, vis+no, 0);

		FOR (i, 0, no - 1) if (!vis[i]) {
			dfs(i, -1, get_sum(i, -1));
		}
		for (int x : it.S) {
			connect(e[x].F, e[x].S);
		}
	}
	
	ll val = *max_element(ans + 1, ans + n);
	cout << 2*val << " ";
	vi yo; FOR (i, 1, n - 1) if (ans[i] == val) yo.push_back(i);
	cout << sz(yo) << "\n";
	for (int i : yo) cout << i << " ";

	return 0;
}