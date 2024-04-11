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

	int n, m, x; cin >> n >> m >> x;
	if (n > m) return cout << 0, 0;

	vector<vector<vector<int>>> dp(2, vector<vi>(n + 1, vi(n + 1, 0)));

	dp[1][0][0] = 1;
	int now = 0, prv = 1;
	NFOR (i, m, 1) {
		FOR (j, 0, n) FOR (k, 0, n) dp[now][j][k] = 0;
		FOR (j, 0, n) {
			FOR (k, 0, n) {
				if (i != x) dp[now][j][k] = dp[prv][j][k];
				if (j != n and k) dp[now][j][k] += dp[prv][j + 1][k - 1]; if (dp[now][j][k] >= inf) dp[now][j][k] -= inf;
				if (j) {if (i != x) {dp[now][j][k] += dp[prv][j - 1][k]; if (dp[now][j][k] >= inf) dp[now][j][k] -= inf;}}
				if (k) {dp[now][j][k] += dp[prv][j][k-1]; if (dp[now][j][k] >= inf) dp[now][j][k] -= inf;}
			}
		}
		swap(now, prv);
	}
	int ans = dp[prv][0][n];
	FOR (i, 1, n) ans = (ans * 1LL * i) % inf;

	cout << ans << "\n";

	return 0;
}