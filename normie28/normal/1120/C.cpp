#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e3 + 17, base = maxn, base2 = 777, mod = 1e9 + 7, mod2 = 9e8 + 1723;
int n, a, b, dp[maxn];
string s;
int h[maxn], h2[maxn], po[maxn], po2[maxn];
pair<int, int> getHash(int l, int r){
	return {(h[r] - (ll) h[l] * po[r - l] % mod + mod) % mod,
			(h2[r] - (ll) h2[l] * po2[r - l] % mod2 + mod2) % mod2};
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> a >> b >> s;
	po[0] = po2[0] = 1;
	for(int i = 1; i <= n; i++){
		po[i] = (ll) po[i - 1] * base % mod;
		po2[i] = (ll) po2[i - 1] * base2 % mod2;
		h[i] = ((ll) h[i - 1] * base + s[i - 1]) % mod;
		h2[i] = ((ll) h2[i - 1] * base2 + s[i - 1]) % mod2;
	}
	for(int i = 1; i <= n; i++){
		dp[i] = a + dp[i - 1];
		for(int j = i - 1, ptr = i - 1; j >= 0; j--){
			if(ptr > j)
				ptr = j;
			while(ptr >= i - j && getHash(ptr - (i - j), ptr) != getHash(j, i))
				ptr--;
			if(ptr >= i - j && getHash(ptr - (i - j), ptr) == getHash(j, i))
				dp[i] = min(dp[i], b + dp[j]);
		}
	}
	cout << dp[n] << '\n';
}