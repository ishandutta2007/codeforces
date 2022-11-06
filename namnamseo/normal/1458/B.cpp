#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> pll;
void cppio(){ ios_base::sync_with_stdio(0); cin.tie(0); }
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define x first
#define y second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define sz(x) (int)(x).size()

const int maxn = 100 + 10;

int n;
int cap[maxn];
int wat[maxn];

int dp[101][10001];

int main()
{
	cppio();
	cin >> n;
	rrep(i, n) cin >> cap[i] >> wat[i];

	memset(dp, 0xf0, sizeof(dp));
	const int inf = dp[0][0];
	dp[0][0] = 0;
	rrep(i, n) {
		for(int use=min(100, i); use; --use) {
			for(int j=10000; j>=cap[i]; --j) {
				int &bef = dp[use-1][j-cap[i]];
				if (bef == inf) continue;
				dp[use][j] = max(dp[use][j],
					bef + wat[i]);
			}
		}
	}

	int sw = accumulate(wat+1, wat+n+1, 0);

	rrep(i, n) {
		double ans = 0;
		for (int j=0; j<=10000; ++j) {
			int v = dp[i][j];
			if (v == inf) continue;
			ans = max(ans, min(
				(double) j,
				(double) 0.5 * (sw + v)));
		}
		cout.precision(15);
		cout << fixed << ans << '\n';
	}

	return 0;
}