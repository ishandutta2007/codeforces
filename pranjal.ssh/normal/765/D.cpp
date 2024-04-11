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
template <class T> void dbs(string str, T t) {cout << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cout << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void prc(T a, T b) {cout << "["; for (T i = a; i != b; ++i) {if (i != a) cout << ", "; cout << *i;} cout << "]\n";}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	vi f(n + 1); FOR (i, 1, n) cin >> f[i];
	vi good(n + 1), g(n + 1), h(1);
	
	FOR (i, 1, n) {
		if (f[i] == i) {
			h.push_back(i);
			g[i] = sz(h) - 1;
			good[i] = 1;
		}
	}
	FOR (i, 1, n) {
		if (not good[f[i]]) {
			cout << "-1\n";
			return 0;
		}
		g[i] = g[f[i]];
	}
	int m = sz(h) - 1;
	cout << m << "\n";
	FOR (i, 1, n) cout << g[i] << " \n"[i == n];
	FOR (i, 1, m) cout << h[i] << " \n"[i == m];

	return 0;
}