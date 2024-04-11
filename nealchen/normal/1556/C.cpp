#include <bits/stdc++.h>
const int N=1000;
int n, c[N];
long long s[N+1], mins[N+1];
int main() {
	scanf("%d", &n);
	for(int i=0; i<n; ++i) {
		scanf("%d", c+i);
		s[i+1]=s[i]+(i&1?-1:1)*c[i];
	}
	long long ans=0;
	for(int i=0; i<n; i+=2) {
		mins[i]=1e18;
		for(int j=i+1; j<=n; ++j) mins[j]=std::min(mins[j-1], s[j]-s[i]);
		for(int j=i+1; j<n && mins[j]>=0; j+=2) {
			long long min=std::max(0ll, s[j]-s[i]-c[j]), max=std::min(mins[j], c[i]-1ll);
			if(min<=max) ans+=max-min+1;
		}
	}
	printf("%lld\n", ans);
	return 0;
}