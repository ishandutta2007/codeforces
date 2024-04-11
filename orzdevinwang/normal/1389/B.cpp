#include<bits/stdc++.h>
#define N 310000
#define int long long
using namespace std;
int T, n, a[N], qz[N], maxn[N], k, z, Ans;
signed main() {
	scanf("%lld",&T);
	while(T--) {
		scanf("%lld%lld%lld",&n,&k,&z), z = min(z, k / 2), ++k, Ans = 0;
		for(int i = 1; i <= n; i++) {
			scanf("%lld",&a[i]), qz[i] = qz[i-1] + a[i];
			if(i > 1) maxn[i] = max(maxn[i-1], a[i] + a[i-1]);
		}
		for(int i = 0; i <= z; i++) 
			Ans = max(Ans, qz[k - i * 2] + maxn[k - i * 2 + 1] * i);
		printf("%lld\n", Ans);
	}
    return 0;
}