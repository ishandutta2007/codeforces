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



int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m; cin >> n >> m;
	vector<vi> g(n), gr(n);
	FOR (i, 0, n - 1) {
		int t; cin >> t; while (t--) {
			int x; cin >> x; --x;
			g[i].push_back(x);
			gr[x].push_back(i);
		}
	}
	int s; cin >> s; --s;
	vector<int> dp(n);
	vector<vi> par(n, vi(2, -1));
	queue<int> q;
	FOR (i, 0, n - 1) if (g[i].empty()) dp[i] = 1, q.push(i);


	while (!q.empty()) {
		int u = q.front();
		q.pop();
		if (dp[u] & 1) {
			for (int v : gr[u]) if (!(dp[v] & 2)) {
				dp[v] |= 2;
				par[v][1] = u;
				q.push(v);
			}
		}
		if (dp[u] & 2) {
			for (int v : gr[u]) if (!(dp[v] & 1)) {
				dp[v] |= 1;
				par[v][0] = u;
				q.push(v);
			}
		}
	}

	vector<int> vis(n);
	int cycle = 0;
	function<void(int)> dfs = [&] (int u) {
		vis[u] = 1;
		for (int v : g[u]) {
			if (vis[v] == 1) {
				cycle = 1;
			}
			if (vis[v] == 0) {
				dfs(v);
			}
		}
		vis[u] = 2;
	};
	dfs(s);
	

	if (dp[s] == 1 and !cycle) {
		cout << "Lose\n";
	} else if (dp[s] <= 1 and cycle) {
		cout << "Draw\n";
	} else {
		cout << "Win\n";
		int turn = 1;
		cout << s + 1 << " ";
		while (!g[s].empty()) {
			s = par[s][turn];
			assert(s != -1);
			turn ^= 1;
			cout << s + 1 << " ";
		}
		
	}

	return 0;
}