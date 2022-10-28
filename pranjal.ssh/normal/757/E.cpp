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
template <class T> void dbs(string str, T t) {cerr << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cerr << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T> void prc(T a, T b) {cerr << "["; for (T i = a; i != b; ++i) {if (i != a) cerr << ", "; cerr << *i;} cerr << "]\n";}


const int N = 1e6;
int sv[N + 10];
int dp[N+10][21];
inline int mul(int a, int b) {return ((a*1LL*b) % inf);}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	dp[0][0] = 1;
	FOR (i, 1, 20) dp[0][i] = 2 + dp[0][i - 1];
	FOR (i, 1, N) {
		FOR (j, 0, 20) {
			dp[i][j] = dp[i - 1][j];
		}
		FOR (j, 1, 20) {
			dp[i][j] += dp[i][j - 1];
			if (dp[i][j] >= inf) dp[i][j] -= inf;
		}
	}

	FOR (i, 1, N) sv[i] = i;
	FOR (i, 2, 1000) {
		if (sv[i] == i) {
			for (int j = i*i; j <= N; j += i)
				sv[j] = i;
		}
	}

	int q; cin >> q;
	while (q--) {
		int r, n; cin >> r >> n;
		int ans = 1;
		while (n > 1) {
			int x = sv[n];
			int f = 0;

			while (n > 1 and n % x == 0) n/=x, ++f;
			int y = dp[r][f] - dp[r][f - 1];
			if (y < 0) y += inf;
			ans = mul(ans, y);
		}
		cout << ans << "\n";
	}

	return 0;
}