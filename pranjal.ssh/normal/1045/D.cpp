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
template <class T> void prc(T a, T b) {cout << "["; for (T i = a; i != b; ++i) {if (i != a) cout << ", "; cout << *i;} cout << "]"; cout << endl;}

vector<vi> g;
vector<double> a, s;
vector<int> p;
void dfs(int i) {
	for (int j : g[i]) if (j != p[i]) {
		s[i] += 1 - a[j];
		p[j] = i;
		dfs(j);
	}
}
int main()
{
 	int n; cin >> n; a.resize(n);
 	FOR (i, 0, n - 1) scanf("%lf", &a[i]);
 	g.resize(n); p = vi(n, -1); s.resize(n);
 	FOR (i, 1, n-1) {
 		int x, y; scanf("%d %d", &x, &y);
 		g[x].push_back(y); g[y].push_back(x);
 	}
 	dfs(0);
 	double ans = 1 - a[0];
 	FOR (i, 0, n - 1) ans += s[i] * a[i];

 	int q; cin >> q; while (q--) {
 		int x; double pr;
 		scanf("%d %lf", &x, &pr);
 		
 		ans -= 1 - a[0];
 		ans -= s[x] * a[x];
 		if (x != 0) ans -= s[p[x]] * a[p[x]];

 		if (x != 0) s[p[x]] -= 1 - a[x], s[p[x]] += 1 - pr;
 		a[x] = pr;

		ans += 1 - a[0];
		ans += s[x] * a[x];
		if (x != 0) ans += s[p[x]] * a[p[x]]; 		
		printf("%.6lf\n", ans);
 	}


   return 0;
}