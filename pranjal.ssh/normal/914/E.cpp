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

const int N = 2e5+10;
vi g[N];
int vis[N], sub[N];
ll val[N], ans[N];
int f[1 << 20];
int curn = 0;
char s[N];
void pre(int x, int p) {
	sub[x] = 1;
	++curn;
	for (int y : g[x]) if (y != p and !vis[y]) {
		pre(y, x);
		sub[x] += sub[y];
	}
}

void mark(int x, int p, int mask) {
	mask ^= (1 << s[x]);
	f[mask]++;
	for (int y : g[x]) if (p != y and !vis[y]) {
		mark(y, x, mask);
	}
}
ll sum = 0;
void simple(int x, int p, int mask) {
	mask ^= (1 << s[x]);
	if (mask == 0 or __builtin_popcount(mask) == 1) {
		val[x]++;
		sum += 1;
	}
	for (int y : g[x]) if (p != y and !vis[y]) {
		simple(y, x, mask);
	}
}


void unmark(int x, int p, int mask) {
	mask ^= (1 << s[x]);
	f[mask] = 0;
	for (int y : g[x]) if (p != y and !vis[y]) {
		unmark(y, x, mask);
	}
}
void clear(int x, int p, int mask) {
	mask ^= (1 << s[x]);
	f[mask] = val[x] = 0;
	FOR (i, 0, 19) f[mask ^ (1 << i)] = 0;
	for (int y : g[x]) if (p != y and !vis[y]) {
		clear(y, x, mask);
	}
}
void prop(int x, int p, int mask) {
	mask ^= (1 << s[x]);
	val[x] += f[mask];
	FOR (i, 0, 19) val[x] += f[mask ^ (1 << i)];
	for (int y : g[x]) if (p != y and !vis[y]) {
		prop(y, x, mask);
	}
}

void backprop(int x, int p) {
	for (int y : g[x]) if (p != y and !vis[y]) {
		backprop(y, x);
		val[x] += val[y];
	}
	ans[x] += val[x];
}

int centroid(int x, int p) {
	for (int y : g[x]) if (y != p and !vis[y] and sub[y] > curn/2) return centroid(y, x);
	return x;
}

void dfs(int x) {
	curn = 0;
	pre(x, 0);
	x = centroid(x, 0);
	sum = 0;
	for (int y : g[x]) if (!vis[y]) {
		prop(y, x, 1 << s[x]);
		mark(y, x, 0);
	}

	for (int y : g[x]) if (!vis[y]) {
		unmark(y, x, 0);
	}

	reverse(all(g[x]));


	for (int y : g[x]) if (!vis[y]) {
		prop(y, x, 1 << s[x]);
		mark(y, x, 0);
	}

	simple(x, 0, 0);
	backprop(x, 0);
	ans[x] += sum;
	ans[x] -= (val[x] + sum) / 2;
	clear(x, 0, 0);

	vis[x] = 1;
	for (int y : g[x]) if (!vis[y]) {
		dfs(y);
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	FOR (i, 1, n - 1) {
		int x, y; cin >> x >> y;
		g[x].push_back(y), g[y].push_back(x);
	}
	FOR (i, 1, n) cin >> s[i], s[i] -= 'a';

	dfs(1);

	FOR (i, 1, n) cout << ans[i] << " ";

	return 0;
}