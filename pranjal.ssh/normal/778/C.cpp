#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define FOR(i,a,b) for (int i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(int i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
typedef long long ll; typedef pair <int, int> ii; typedef vector <int> vi; const int inf = 1e9 + 7;
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class T> void dbs(string str, T t) {cout << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cout << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void prc(T a, T b) {cout << "["; for (T i = a; i != b; ++i) {if (i != a) cout << ", "; cout << *i;} cout << "]\n";}

const int N = 1e6;
int n;
map<int, vi> g[N];
int ans[N], sub[N];
void dfs(int u, int d) {
	sub[u] = 1;
	for (auto it : g[u]) {
		g[it.S[0]][it.F].erase(find(all(g[it.S[0]][it.F]), u));
		if (g[it.S[0]][it.F].empty()) g[it.S[0]].erase(it.F);
		dfs(it.S[0], d + 1);
		sub[u] += sub[it.S[0]];
	}
	if (sub[u] > 1)
	ans[d] -= sub[u];
}
int ctr;
vector<ii> toErase;
int insert(int to, int from) {
	int ans = 0;
	for (auto it : g[from]) {
		if (g[to].count(it.F)) {
			ans += insert(g[to][it.F][0], it.S[0]);
		}
		else {
			g[to][it.F].push_back(++ctr);
			if (to <= n) toErase.emplace_back(to, it.F);
			++ans;
			ans += insert(ctr, it.S[0]);
		}
	}
	return ans;
}

void test(int u, int d) {
	if (g[u].empty()) return;
	for (auto it : g[u]) {
		test(it.S[0], d + 1);
	}
	ii mx;
	for (auto it : g[u]) {
		mx = max(mx, ii(sub[it.S[0]], it.F));
	}
	ctr = n;
	ans[d] += mx.F;
	for (auto it : g[u]) {
		if (it.F == mx.S) continue;
		ans[d] += insert(g[u][mx.S][0], it.S[0]);
	}
	FOR (it, n + 1, ctr) g[it].clear();
	for (ii it : toErase) {
		g[it.F].erase(it.S);
	}
	toErase.clear();
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;

	FOR (_, 1, n - 1) {
		int u, v; char x; cin >> u >> v >> x;
		g[u][x - 'a'].push_back(v);
		g[v][x - 'a'].push_back(u);
	}
	FOR (i, 1, n) ans[i] = n;
	dfs(1, 1);
	test(1, 1);
	int yo = n;
	FOR (i, 1, n) yo = min(yo, ans[i]);

	cout << yo << "\n";
	FOR (i, 1, n) if (ans[i] == yo) {
		cout << i << "\n";
		return 0;
	}
}