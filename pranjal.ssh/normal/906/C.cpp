#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
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


bool dp[1 << 22];
int hit[1 << 22];
int g[22];
int n, m;
ii ans;


int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	FOR (i, 0, m - 1) {
		int u, v; cin >> u >> v; --u, --v;
		g[u] |= 1 << v;
		g[v] |= 1 << u;
	}
	if (2 * m == n * (n - 1)) {
		cout << "0\n";
		return 0;
	}
	
	ans = ii(n, (1 << n) - 1);

	FOR (i, 1, (1 << n) - 1) {
		int j = i & (i - 1);
		hit[i] = i;
		hit[i] |= (hit[j] | (i ^ j) | g[__builtin_ctz(i ^ j)]);
		dp[i] = !j;
		if (!dp[i]) {
			FOR (k, 0, n - 1) if (i & (1 << k)) {
				if (dp[i ^ (1 << k)] and (g[k] & (i ^ (1 << k)))) {
					dp[i] = true;
					break;
				}
			}
		}
		if (dp[i] and hit[i] == (1 << n) - 1) ans = min(ans, ii(__builtin_popcount(i), i));
	}
	

	cout << ans.F << "\n";
	FOR (i, 0, n - 1) if (ans.S & (1 << i)) cout << i + 1 << " ";



	return 0;
}