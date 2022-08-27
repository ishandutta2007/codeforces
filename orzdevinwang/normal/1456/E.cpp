#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
#define ull unsigned long long 
using namespace std;
const int N = 1 << 6; 
int n, k;
ll L[N], R[N], c[N], dp[N][N][N][2][2][2][2];
ll calc (int o, int l, int r, int lc, int lo, int rc, int ro) {
	if (o == k) 
		return r - l == 1 ? 0 : 1e18;
	if (dp[o][l][r][lc][lo][rc][ro] != -1) 
		return dp[o][l][r][lc][lo][rc][ro]; 
	ll vl = ((!lc ? L[l] : R[l]) >> o & 1) ^ lo, vr = ((!rc ? L[r] : R[r]) >> o & 1) ^ ro;
	ll ret = calc (o + 1, l, r, lc, 0, rc, 0) + ((l != 0 && r != n + 1) ? (vl ^ vr) * c[o] : 0);
	L(i, l + 1, r - 1) {
		if(!o) {
			ret = min(ret, calc (o, l, i, lc, lo, 0, 0) + calc (o, i, r, 0, 0, rc, ro));
			ret = min(ret, calc (o, l, i, lc, lo, 1, 0) + calc (o, i, r, 1, 0, rc, ro));
		}
		if((L[i] >> (o + 1)) != (R[i] >> (o + 1))) {
			if(!(L[i] >> o & 1)) 
				ret = min(ret, calc (o, l, i, lc, lo, 0, 1) + calc (o, i, r, 0, 1, rc, ro));
			if(R[i] >> o & 1) 
				ret = min(ret, calc (o, l, i, lc, lo, 1, 1) + calc (o, i, r, 1, 1, rc, ro));
		}
	} 
//	cout << o << ' ' << l << ' ' << r << ' ' << lc << ' ' << lo << ' ' << rc << ' ' << ro << " : " <<
//	ret << '\n';
	return dp[o][l][r][lc][lo][rc][ro] = ret ;
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	memset(dp, -1, sizeof(dp));
	cin >> n >> k;
	L(i, 1, n) cin >> L[i] >> R[i];
	L(i, 0, k - 1) cin >> c[i];
	cout << calc (0, 0, n + 1, 0, 0, 0, 0) << '\n'; 
	return 0;
}