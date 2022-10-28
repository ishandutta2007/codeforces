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
template <class T> void dbs(string str, T t) {cout << str << " : " << t << endl;}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cout << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void prc(T a, T b) {cout << "["; for (T i = a; i != b; ++i) {if (i != a) cout << ", "; cout << *i;} cout << "]";cout<<endl;}

vector<vector<ii>> g;
vi vis, d, ans;
int dfs(int u) {
	vis[u] = 1;
	int x = d[u] == 1;
	for (ii j : g[u]) {
		if (vis[j.F]) continue;
		int y = dfs(j.F);
		if (y & 1) {
			ans.push_back(j.S);
		}
		x += y;
	}
	return x;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m; cin >> n >> m;
	d = vi(n); FOR (i, 0, n - 1) cin >> d[i];
	int tot = count_if(all(d), [](int i){return i == 1;});
	if ((tot&1)) {
		for (int &i : d) {
			if (i == -1) {
				i = 1;
				tot++;
				break;
			}
		}
	}

	if (tot & 1) {
		cout << "-1\n";
		return 0;
	}
	g.resize(n), vis.resize(n);
	FOR (i, 1, m) {
		int u, v; cin >> u >> v;
		--u, --v;
		g[u].emplace_back(v, i);
		g[v].emplace_back(u, i);
	}

	dfs(0);
	sort(all(ans));
	cout << ans.size() << "\n";
	for (int i : ans) cout << i << " ";

	return 0;
}