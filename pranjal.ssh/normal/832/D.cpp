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

const int N = 1e5 + 10;
int p[17][N], d[N], in[N], out[N], ctr;
vi g[N];
void dfs(int i, int par) {
	in[i] = ++ctr;
	for (int j : g[i]) if (j != par) {
		p[0][j] = i;
		d[j] = d[i] + 1;
		dfs(j, i);
	}
	out[i] = ctr;
}
inline bool sub(int a, int c) {return in[c] >= in[a] && in[c] <= out[a];}
int lca(int u, int v) {
	if (sub(u, v)) return u;
	NFOR (i, 16, 0) {
		int to = p[i][u];
		if (to && !sub(to, v)) u = to;
	}
	return p[0][u];
}
int ans(int f, int s, int t) {
	if (sub(f, s) && sub(f, t)) return -d[f] + d[lca(s, t)] + 1;
	int nf = f;
	NFOR (i, 16, 0) {
		int to = p[i][nf];
		if (to && !sub(to, s) && !sub(to, t)) nf = to;
	}
	nf = p[0][nf];
	int ans = -d[nf] + d[f];
	bool S = sub(nf, s);
	bool T = sub(nf, t);
	if (S && T) return -d[nf] + d[lca(s, t)] + 1 + ans;
	return 1 + ans;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n, q; cin >> n >> q;
	for (int i = 2; i <= n; ++i) {
		int x; cin >> x;
		g[i].push_back(x), g[x].push_back(i);
	}
	dfs(1, 0);
	FOR (i, 1, 16) {
		FOR (j, 1, n) {
			p[i][j] = p[i-1][p[i-1][j]];
		}
	}

	while (q--) {
		int a, b, c; cin >> a >> b >> c;
		cout << max({ans(a, b, c), ans(b, a, c), ans(c, a, b)}) << "\n";
	}

	return 0;
}