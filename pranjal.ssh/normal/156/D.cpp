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
struct DSU {
	vi p, r;
	DSU(int n):p(n),r(n, 1){FOR(i, 0, n - 1)p[i] = i;}

	int get(int i) {
		if (p[i] != i)p[i] = get(p[i]);
		return p[i];
	}
	int connect(int i, int j) {
		int x = get(i), y = get(j);
		if (x == y) return 0;
		if (r[x] > r[y]) swap(x, y);
		p[x] = y;
		r[y] += r[x];
		return 1;
	}
};//
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m, k; cin >> n >> m >> k;
	DSU dsu(n);
	FOR (i, 1, m) {
		int a, b; cin >> a >> b;
		--a, --b;
		dsu.connect(a, b);
	}
	int ans = 1;
	int no = 0;
	FOR (i, 0, n - 1) if (i == dsu.get(i)) ans = (ans * 1LL * dsu.r[i]) % k, no++;
	FOR (i, 1, no - 2) ans = (ans * 1LL * n) % k;
	if (no == 1) ans = 1 % k;
	cout << ans;

	return 0;
}