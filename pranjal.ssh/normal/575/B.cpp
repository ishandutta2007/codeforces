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
vector<ii> g[N];
int jump[21][N];
int st[N], en[N], l[N];
int val[2][N];
int ctr;
void dfs(int i) {
	st[i] = ++ctr;
	for (ii j : g[i]) if (st[j.F] == 0) {
		jump[0][j.F] = i;
		l[j.F] = l[i] + 1;
		dfs(j.F);
	}
	en[i] = ctr;
}
bool insub(int i, int j) {
	return st[j] >= st[i] and st[j] <= en[i];
}
int lca(int i, int j) {
	if (l[j] > l[i]) swap(i, j);
	if (insub(j, i)) return j;
	int u = i;
	NFOR (it, 20, 0) {
		if (jump[it][u]) {
			if (!insub(jump[it][u], j)) u = jump[it][u];
		}
	}
	return jump[0][u];
}
int ans = 0;
int expo(int n, int m) {
	int ans = 1;
	while (m) {
		if (m & 1) ans = (ans * 1LL * n) % inf;
		m >>= 1;
		n = (n * 1LL * n) % inf;
	}
	return ans;
}
void calc(int i) {
	for (ii j : g[i]) if (jump[0][i] != j.F) {
		calc(j.F);
		if (j.S) {
			ans += expo(2, val[j.S < 0][j.F]) - 1;
			if (ans >= inf) ans -= inf;
			if (ans < 0) ans += inf;
		}
		val[0][i] += val[0][j.F];
		val[1][i] += val[1][j.F];
		if (val[0][i] >= inf) val[0][i] -= inf;
		if (val[1][i] >= inf) val[1][i] -= inf;
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	map<int, int> mp;
	FOR (i, 1, n - 1) {
		int a, b, x; cin >> a >> b >> x;
		g[a].emplace_back(b, x), g[b].emplace_back(a, -x);
	}
	dfs(1);
	FOR (i, 1, 20) {
		FOR (j, 1, n) jump[i][j] = jump[i-1][jump[i-1][j]];
	}
	

	int x = 1;
	int k; cin >> k; while (k--) {
		int y; cin >> y;
		int z = lca(x, y);
		val[0][x]++, val[0][z]--;
		val[1][y]++, val[1][z]--;
		x = y;
	}
	calc(1);
	cout << ans << "\n";


	return 0;
}