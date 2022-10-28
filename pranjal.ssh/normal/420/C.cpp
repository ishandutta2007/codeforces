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

	int n, p; cin >> n >> p;
	vector<vi> g(n), gg(n);
	vi d(n);
	FOR (i, 1, n) {
		int x, y; cin >> x >> y;
		--x, --y;
		d[x]++, d[y]++;
		g[x].push_back(y), g[y].push_back(x);
	}
	ll ans = 0;
	FOR (i, 0, n - 1) sort(all(g[i]));
	FOR (i, 0, n - 1) {
		vi yo = g[i]; yo.erase(unique(all(yo)), yo.end());
		for (int j : yo) {
			int cnt = upper_bound(all(g[i]), j) - lower_bound(all(g[i]), j);
			gg[i].push_back(d[j]);
			ans += (d[i] + d[j] - cnt >= p);
		}
		sort(all(gg[i]));
	}

	

	vi dd = d;
	sort(all(dd));

	FOR (i, 0, n - 1) {
		int can = dd.end() - lower_bound(all(dd), p - d[i]);
		int nn = gg[i].end() - lower_bound(all(gg[i]), p - d[i]);
		ans += can - nn;
		if (d[i] + d[i] >= p) --ans;
	}

	cout << ans/2 << "\n";

	return 0;
}