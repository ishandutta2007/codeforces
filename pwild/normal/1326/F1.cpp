#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pll;
typedef vector<bool> vb;
const ll oo = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;
#define sz(c) ll((c).size())
#define all(c) begin(c), end(c)
#define FOR(i,a,b) for (ll i = (a); i < (b); i++)
#define FORD(i,a,b) for (ll i = (b)-1; i >= (a); i--)
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define TR(X) ({ if(1) cerr << "TR: " << (#X) << " = " << (X) << endl; })

vector<vvl> calc(vector<string> know, ll k) {
	ll n = sz(know);
	
	vector<vvl> dp(1 << n, vvl(n));

	FOR(mask,0,1 << n) FOR(i,0,n) if (mask & (1 << i)) {
		dp[mask][i].resize(1 << (__builtin_popcount(mask)-1));
	}
	
	FOR(i,0,n) dp[1 << i][i][0] = 1;

	FOR(mask,0,1 << n) {
		ll cnt = __builtin_popcount(mask);
		if (cnt >= k) continue;
		
		FOR(i,0,n) if (mask & (1 << i)) {
			FOR(j,0,n) if (!(mask & (1 << j))) {
				ll nmask = mask | (1 << j);
				FOR(s,0,sz(dp[mask][i])) {
					ll ns = 2*s + (know[i][j]-'0');
					dp[nmask][j][ns] += dp[mask][i][s];
				}
			}
		}
	}

	return dp;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;
	vector<string> know(n);
	FOR(i,0,n) cin >> know[i];
	
	vector<string> knowi(n, string(n,' '));
	FOR(i,0,n) FOR(j,0,n) knowi[i][j] = know[j][i];
	
	ll kL = n/2, kR = n-kL;
	auto dpL = calc(know, kL);
	auto dpR = calc(knowi, kR);


	vl rev(1 << (kR-1));
	FOR(mask,0,sz(rev)) {
		FOR(i,0,kR-1) if (mask & (1 << i)) {
			rev[mask] |= 1 << (kR-2-i);
		}
	}
	
	vector<long long> res(1 << (n-1));
	FOR(maskL,0,1 << n) if (__builtin_popcount(maskL) == kL) {
		ll maskR = ((1 << n) - 1) ^ maskL;
		FOR(iL,0,n) if (maskL & (1 << iL)) {
			FOR(iR,0,n) if (maskR & (1 << iR)) {
/*				vector<pll> vL;
				FOR(sL,0,sz(dpL[maskL][iL])) if (dpL[maskL][iL][sL]) {
					vL.eb(sL, dpL[maskL][iL][sL]);
				}
				vector<pll> vR;
				FOR(sR,0,sz(dpR[maskR][iR])) if (dpR[maskR][iR][sR]) {
					vR.eb(sR, dpR[maskR][iR][sR]);
				}
				
				for (auto [sL,cntL]: vL) for (auto [sR,cntR]: vR) {
					ll s = ((2*sL + (know[iL][iR]-'0')) << (kR-1)) + rev[sR];
					res[s] += cntL * 1LL * cntR;
				}
				*/
				FOR(sL,0,sz(dpL[maskL][iL])) if (dpL[maskL][iL][sL]) {
					FOR(sR,0,sz(dpR[maskR][iR])) if (dpR[maskR][iR][sR]) {
						ll s = ((2*sL + (know[iL][iR]-'0')) << (kR-1)) + rev[sR];
						res[s] += dpL[maskL][iL][sL] * 1LL * dpR[maskR][iR][sR];
					}
				}
			}
		}
	}
	
	FOR(i,0,sz(res)) cout << res[i] << " \n"[i+1==sz(res)];
}