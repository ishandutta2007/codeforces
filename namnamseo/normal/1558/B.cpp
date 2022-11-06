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

const int maxn = int(4e6) + 10;

int n, mod;

int dp[maxn];
int ad[maxn];

inline void Z(int &x) { if (x >= mod) x -= mod; }

int main()
{
	cppio();
	cin >> n >> mod;

	dp[1] = 1;

	for (int i=1; i<=n; ++i) {
		ad[i] += ad[i-1]; Z(ad[i]);
		dp[i] += ad[i]; Z(dp[i]);
		for (int z=1;;++z) {
			ll nl = i*1ll*z, nr = z*1ll*(i+1);
			if (nl > n) break;
			nr = min(int(nr), n+1);
			if (nl >= nr) continue;
			ad[nl] += dp[i];
			Z(ad[nl]);
			ad[nr] += mod-dp[i];
			Z(ad[nr]);
		}
		ad[i+1] += dp[i];
		Z(ad[i+1]);
	}

	cout << dp[n] << '\n';

	return 0;
}