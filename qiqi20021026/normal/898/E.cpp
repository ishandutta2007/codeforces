#include<bits/stdc++.h>

using namespace std;

#define N 300000
#define LL long long

LL n,ff,gg,ans,a[N],f[N],g[N];

int main(){
	scanf("%lld",&n);
	for (LL i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		LL j=sqrt(a[i]); if (j*j==a[i]) f[++ff]=a[i]==0?2:1; else g[++gg]=min(a[i]-j*j,(j+1)*(j+1)-a[i]);
	}
	if (ff<n/2){
		sort(g+1,g+gg+1);
		for (LL i=1;i<=n/2-ff;i++) ans+=g[i];
	}
	if (gg<n/2){
		sort(f+1,f+ff+1);
		for (LL i=1;i<=n/2-gg;i++) ans+=f[i];
	}
	printf("%lld\n",ans);
	
	return 0;
}