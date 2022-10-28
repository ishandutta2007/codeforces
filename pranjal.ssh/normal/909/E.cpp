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
template <class T> void prc(T a, T b) {cout << "["; for (T i = a; i != b; ++i) {if (i != a) cout << ", "; cout << *i;} cout << "]"; cout << endl;}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m; cin >> n >> m;
	vi a(n); FOR (i, 0, n - 1) cin >> a[i];
	vector<vi> g(n); vi d(n);
	while (m--) {
		int x, y; cin >> x >> y;
		g[y].push_back(x);
		d[x]++;
	}
	vector<vi> M(2);
	
	FOR (i, 0, n - 1) {
		if (d[i] == 0) {
			M[a[i]].push_back(i);
		}
	}

	int ans = 0;
	while (sz(M[0])+sz(M[1])) {
		if (!M[0].empty()) {
			int x = M[0].back();
			M[0].pop_back();
			for (int y : g[x]) {
				--d[y];
				if (d[y] == 0) M[a[y]].push_back(y);
			}
		} else {
			++ans;
			while (!M[1].empty()) {
				int x = M[1].back();
				M[1].pop_back();
				for (int y : g[x]) {
					--d[y];
					if (d[y] == 0) M[a[y]].push_back(y);
				}	
			}
		}
	}
	cout << ans << "\n";

	return 0;
}