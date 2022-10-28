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

const int N = 500;
int d[N][N];
bitset<N> dp[N][2][61];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m; cin >> n >> m;
	FOR (it, 1, m) {
		int u, v, t; cin >> u >> v >> t;
		--u, --v;
		d[u][v] = (1 << t);

		dp[u][t][0].set(v);
	}
	FOR (it, 1, 60) {
		int prv = it - 1, now = it;
		FOR (s, 0, 1) {
			FOR (i, 0, n - 1) {
				FOR (j, 0, n - 1) {
					if (dp[i][s][prv].test(j)) 
						dp[i][s][now] |= dp[j][!s][prv];
				}
			}
		}
	}

	ll ans = 0;
	bitset<N> pos;
	pos.set();
	int s = 0;
	NFOR (i, 60, 0) {
		bitset<N> pos2;
		FOR (j, 0, n - 1) {
			if (pos.test(j))
				pos2 |= dp[j][s][i];
		}
		if (pos2.any()) {
			pos = pos2;
			s = !s;
			ans += (1LL << i);
		}
	}
	if (ans > 1e18)
		ans = -1;
	cout << ans << "\n";




	return 0;
}