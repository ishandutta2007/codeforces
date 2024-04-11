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


vi bfs(vector<vi>& g, int s) {
	int n = sz(g);
	vi d(n, inf);
	d[s] = 0;
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int v : g[u]) if (d[v] == inf) {
			d[v] = d[u] + 1;
			q.push(v);
		}
	}
	return d;
}

bool yo[1001][1001];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m, s, t; cin >> n >> m >> s >> t; --s, --t;
	vector<vi> g(n); FOR (i, 0, m - 1) {
		int u, v; cin >> u >> v; --u, --v;
		g[u].push_back(v), g[v].push_back(u);
		yo[u][v] = yo[v][u] = 1;
	}
	if (s > t) swap(s, t);

	vi ds = bfs(g, s), dt = bfs(g, t);
	int ans = 0;
	FOR (i, 0, n - 1) {
		FOR (j, i + 1, n - 1) {
			if (i == s and j == t) {
				continue;
			}
			if (min(ds[i] + 1 + dt[j], ds[j] + 1 + dt[i]) >= ds[t]) {
				ans += !yo[i][j];
			}
		}
	}
	cout << ans;

	return 0;
}