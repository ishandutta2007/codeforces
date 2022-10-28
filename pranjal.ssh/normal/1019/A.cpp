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


int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m; cin >> n >> m;
	vector<ii> a(n);
	vi f(m);
	vector<vi> yo(m);
	FOR (i, 0, n - 1) cin >> a[i].F >> a[i].S, f[--a[i].F]++, yo[a[i].F].push_back(a[i].S);
	FOR (i, 0, m - 1) {
		sort(all(yo[i]));
	}

	ll cost = 1e18;
	vi tmp(f);
	if (f[0] >= n/2 + 1) {
		return cout << "0\n", 0;
	}
	FOR (it, max(f[0], 1), n/2 + 1) {
		f = tmp;
		ll now = 0;
		FOR (i, 1, m - 1) if (f[i] >= it) {
			FOR (j, 0, f[i] - it) now += yo[i][j];
			f[0] += f[i] - it + 1;
			f[i] = it - 1;
		}
		if (f[0] < it) {
			vi lmao;
			FOR (i, 1, m - 1) {
				FOR (j, sz(yo[i]) - f[i], sz(yo[i]) - 1) {
					lmao.push_back(yo[i][j]);
				}
			}

			stable_sort(all(lmao));
			FOR (i, 0, it - f[0] - 1) {
				now += lmao[i];
			}
		}
		cost = min(cost, now);
	}
	cout << cost;

	return 0;
}