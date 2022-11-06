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

int n, m;
char s[3010], t[3010];

char F[3010];
char B[3010];

ll dp[3010][3010];
bitset<3010> vis[3010];
const ll mod = 998'244'353;

ll f(int i, int lc)
{
	ll& ret = dp[i][lc];
	if (vis[i][lc]) return ret;
	vis[i].set(lc);

	int rc = max(0, m - (i-1) - lc);

	if (!lc && !rc) ret = 1;

	if (i > n) return ret;

	if (lc && s[i] == t[lc]) {
		ret = f(i+1, lc-1);
	}

	if ((rc && s[i] == t[m-rc+1]) || !rc) {
		ret += f(i+1, lc);
		ret %= mod;
	}

	return ret;
}

int main()
{
	cppio();
	cin >> (s+1) >> (t+1);
	n = strlen(s+1);
	m = strlen(t+1);

	ll ans = 0;
	for (int i=1; i<=m; ++i) if (t[i] == s[1]) {
		ans += f(2, i-1);
		ans %= mod;
	}

	static int e[3010][3010];
	reverse(t+1, t+m+1);
	e[1][0] = 1;
	for(int i=2; i<=n; ++i) {
		e[i][0] = (e[i-1][0]*2)%mod;
		for(int j=1; j<=m; ++j) {
			e[i][j] = e[i-1][j];
			if (s[i] == t[j])
				(e[i][j] += e[i-1][j-1]) %= mod;
		}
	}

	for(int i=2; i<=n; ++i) {
		(ans += (e[i][m]+mod-e[i-1][m])%mod * 1ll * (n-i+1) % mod) %= mod;
	}

	ans = ans*2%mod;

	cout << ans << '\n';

	return 0;
}