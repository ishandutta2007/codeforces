#include<bits/stdc++.h>
#define N 200010
#define mod 1000000007
#define ll long long
using namespace std;
int n, k;
int suma[N], sumb[N];
int sumc[N], sumd[N];
ll ans, po[N];
char s[N];
void ad(ll x) {
	(ans += x) %= mod;
}
int main() {
	scanf("%d", &n);
	po[0] = 1;
	for(int i = 1; i <= n; i++) po[i] = po[i - 1] * 3 % mod;
	scanf("%s", s + 1);
	for(int i = 1; i <= n; i++) suma[i] = suma[i - 1] + (s[i] == '?'), sumc[i] = sumc[i - 1] + (s[i] == 'a');
	for(int i = n; i >= 1; i--) sumb[i] = sumb[i + 1] + (s[i] == '?'), sumd[i] = sumd[i + 1] + (s[i] == 'c');
	for(int i = 1; i <= n; i++) {
		if(s[i] != '?' && s[i] != 'b') continue;
		int ta = suma[i - 1], tb = sumb[i + 1];
		if(ta >= 1 && tb >= 1) ad(po[ta + tb - 2] * ta % mod * tb % mod);
//		cout << ans << endl;
		if(ta >= 1 && tb >= 0) ad(1ll * po[ta + tb - 1] * ta % mod * sumd[i + 1] % mod);
//		cout << ans << endl;
		if(ta >= 0 && tb >= 1) ad(1ll * po[ta + tb - 1] * tb % mod * sumc[i - 1] % mod);
//		cout << ans << endl;
		if(ta >= 0 && tb >= 0) ad(1ll * po[ta + tb] * sumc[i - 1] % mod * sumd[i + 1] % mod);
//		cout << ans << endl;
	}
	printf("%lld\n", ans);
	return 0;
}