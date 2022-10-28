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
	vector<vector<double>> p(n, vector<double>(n));

	vi a(n);
	FOR (i, 0, n - 1) cin >> a[i];
	FOR (i, 0, n - 1) {
		FOR (j, 0, n - 1) {
			p[i][j] = a[i] < a[j];
		}
	}
	while (m--) {
		int x, y; cin >> x >> y;
		--x, --y;
		auto tx = p[x], ty = p[y];
		FOR (i, 0, n - 1) p[x][i] = 0.5 * (ty[i] + tx[i]);
		p[y] = p[x];
		FOR (i, 0, n - 1) p[i][x] = 1 - p[x][i];
		FOR (i, 0, n - 1) p[i][y] = 1 - p[y][i];
		p[x][x] = p[y][y] = 0;
		p[x][y] = p[y][x] = 0.5;
	}

	double ans = 0;
	FOR (i, 0, n - 1) FOR (j, 0, i - 1) ans += p[i][j];
	cout << fixed << setprecision(10) << ans << "\n";

	return 0;
}