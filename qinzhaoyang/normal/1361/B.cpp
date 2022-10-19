#include <stdio.h>
#include <bits/stdc++.h>
#define int long long

using namespace std;

const int P1 = 1000000007, P2 = 1621836843;

int n, p, k[1000100];

int qkm(int x, int y, int mod){
	int ans=1;
	for(;y;y>>=1,x=(x*x)%mod)
	    if(y&1)ans=(ans*x)%mod;
	return ans;
}

signed main() {
	int T;
	for (scanf("%lld", &T); T; T--) {
		scanf("%lld%lld", &n, &p);
		for(int i = 1; i <= n; i++)
			scanf("%lld", &k[i]);
		if(p == 1) {
			printf("%lld\n", n & 1);
			continue;
		}
		sort(k + 1, k + n + 1);
		int sum1 = 0, sum2 = 0;
		for(int i = n; i >= 1; i--)
		    if(!sum1 && !sum2) {
		    	sum1 = qkm(p, k[i], P1);
		    	sum2 = qkm(p, k[i], P2);
			}
			else {
				sum1 = (sum1 - qkm(p, k[i], P1) + P1) % P1;
				sum2 = (sum2 - qkm(p, k[i], P2) + P2) % P2;
			}
		printf("%lld\n",sum1);
	} 
	return 0;
}