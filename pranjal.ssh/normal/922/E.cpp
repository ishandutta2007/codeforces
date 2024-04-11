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


	int n, w, b, x; cin >> n >> w >> b >> x;
	
	vector<int> c(n), cost(n);
	FOR (i, 0, n - 1) cin >> c[i];
	FOR (i, 0, n - 1) cin >> cost[i];

	vector<ll> dp(1e4 + 1, -1e18);
	dp[0] = w;

	FOR (i, 0, n - 1) {
		FOR (j, 0, 10000) if (dp[j] >= 0) dp[j] = min(w + j*1LL*b,dp[j] + x); else break;
		int x = c[i];
		int it = 1;
		int sum = 0;
		while (sum + it <= x) {
			NFOR (j, 10000, it) {
				if (dp[j - it] >= it*1LL*cost[i])
					dp[j] = max(dp[j], dp[j - it] - it*1LL*cost[i]);
			}
			sum += it;
			it <<= 1;
		}
		it = x - sum;
		NFOR (j, 10000, it) {
			if (dp[j - it] >= it*1LL*cost[i])
				dp[j] = max(dp[j], dp[j - it] - it*1LL*cost[i]);
		}
	}
	int ans = 0;
	while (ans < 10000 and dp[ans+1] >= 0) ++ans;
	cout << ans;


	return 0;
}