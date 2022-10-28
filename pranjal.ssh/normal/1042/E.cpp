#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define FOR(i,a,b) for (auto i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(auto i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
typedef long long ll; typedef pair <int, int> ii; typedef vector <int> vi; const int inf = 998244353;
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class T> void dbs(string str, T t) {cout << str << " : " << t << endl;}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cout << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void prc(T a, T b) {cout << "["; for (T i = a; i != b; ++i) {if (i != a) cout << ", "; cout << *i;} cout << "]"; cout << endl;}

inline int add(int x, int y) {
	x += y;
	if (x >= inf) x -= inf;
	return x;
}

inline int sub(int x, int y) {
	x -= y;
	if (x < 0) x += inf;
	return x;
}

inline int mul(int x, int y) {
	return (x * 1LL * y) % inf;
}

int expo(int a, int n) {
	int ans = 1;
	while (n) {
		if (n & 1) {
			ans = (ans * 1LL * a) % inf;
		}
		a = (a * 1LL * a) % inf;
		n >>= 1;
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m; cin >> n >> m;
	map<int, vector<ii>> mp;

	vector<vector<int>> a(n, vi(m));
	FOR (i, 0, n - 1) {
		FOR (j, 0, m - 1) {
			cin >> a[i][j];
			mp[a[i][j]].emplace_back(i, j);
		}
	}

	int sumx = 0, sumy = 0;
	int sumsqx = 0, sumsqy = 0;
	int sumdpf = 0;
	int sumf = 0;

	int r, c; cin >> r >> c; --r, --c;
	int ans = 0;
	FOR (i, 0, n - 1) {
		FOR (j, 0, m - 1) {
			if (a[i][j] < a[r][c]) {
				ans = add(ans, expo(sub(j, c), 2));
				ans = add(ans, expo(sub(i, r), 2));
			}
		}
	}
	for (auto it : mp) {
		int ssx = 0, ssy = 0;
		int sx = 0, sy = 0;
		for (auto itt : it.S) {
			sx = add(sx, itt.F);
			ssx = add(ssx, mul(itt.F, itt.F));
			sy = add(sy, itt.S);
			ssy = add(ssy, mul(itt.S, itt.S));
		}
		int now = mul(sumdpf, sz(it.S));

		int xterm = mul(sumf, ssx);
		xterm = add(xterm, mul(sz(it.S), sumsqx));
		xterm = add(xterm, mul(sumx, sumx));
		xterm = add(xterm, mul(sx, sx));
		sumx = add(sumx, sx);
		xterm = sub(xterm, mul(sumx, sumx));
		

		int yterm = mul(sumf, ssy);
		yterm = add(yterm, mul(sz(it.S), sumsqy));
		yterm = add(yterm, mul(sumy, sumy));
		yterm = add(yterm, mul(sy, sy));
		sumy = add(sumy, sy);
		yterm = sub(yterm, mul(sumy, sumy));

		now = add(now, add(xterm, yterm));
		now = mul(now, expo(sumf, inf - 2));

		if (it.F == a[r][c]) {
			cout << mul(add(ans, sumdpf), expo(sumf, inf - 2));
			return 0;
		}

		sumdpf = add(sumdpf, now);
		sumsqx = add(sumsqx, ssx);
		sumsqy = add(sumsqy, ssy);
		sumf += sz(it.S);
	}

	return 0;
}