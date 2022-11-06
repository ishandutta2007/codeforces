#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define f first
#define s second
#define mp make_pair
#define pb push_back
 
const int MAXN = 105;
const ll MOD = 998244353;

string maxVal;
map<int,ll> dp[MAXN][10][10][2][2];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> maxVal;
	int n = maxVal.length();
	ll ans = 0;
	FOR(xp, 1, 10)
		FOR(yp, 1, 10) {
			if(__gcd(xp,yp) != 1) continue;
			F0R(i, n+1) F0R(a, 10) F0R(b, 10) F0R(c, 2) F0R(d, 2) dp[i][a][b][c][d].clear();
			dp[0][0][0][1][1][0] = 1;
			vector<int> va, vb;
			int sz = 0;
			FOR(i, 1, 10) {
				if(xp * i >= 10 || yp * i >= 10) break;
				va.pb(xp*i);
				vb.pb(yp*i);
				sz = i;
			}
			F0R(i, n)
				F0R(c1, 10)
					F0R(c2, 10)
						F0R(a1, 2)
							F0R(a2, 2)
								for(auto x : dp[i][c1][c2][a1][a2]) {
									F0R(nd, 10) {
										int nd1 = nd * xp + c1;
										int nd2 = nd * yp + c2;
										int na1 = a1&&nd1%10==maxVal[n-i-1]-'0'||nd1%10<maxVal[n-i-1]-'0';
										int na2 = a2&&nd2%10==maxVal[n-i-1]-'0'||nd2%10<maxVal[n-i-1]-'0';
										int m1 = x.f >> sz;
										int m2 = x.f & (1 << sz) - 1;
										auto i1 = find(va.begin(), va.end(), nd1%10);
										auto i2 = find(vb.begin(), vb.end(), nd2%10);
										if(i1 != va.end()) m1 |= 1<<i1-va.begin();
										if(i2 != vb.end()) m2 |= 1<<i2-vb.begin();
										int nmap = m1 << sz | m2;
										dp[i+1][nd1/10][nd2/10][na1][na2][nmap] = (x.s + dp[i+1][nd1/10][nd2/10][na1][na2][nmap]) % MOD;
									}
								}
			for(auto x : dp[n][0][0][1][1])
				if(__builtin_popcount(x.f >> sz & x.f))
					ans = (ans + x.s) % MOD;
		}
	cout << ans << endl;
    return 0;
}