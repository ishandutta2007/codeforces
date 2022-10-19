#include<bits/stdc++.h>

using namespace std;

#define LL long long
#define N 600000

const LL mod=998244353;
LL n,m,q,ans,l,r,f[N],pre[N],sum[N],cnt[N],mn[N];
char a[N];

int main(){
	scanf("%lld%lld%s",&n,&m,a+1); l=1,r=n;
	f[n]=n; f[n-1]=n-1;
	for (LL i=n-2;i>=1;i--)
		if (a[i]==a[i+2]) f[i]=f[i+2];
		else f[i]=i;
	for (LL i=1;i<=n-1;i++) f[i]=min(f[i],f[i+1])+1;
	for (LL i=1;i<n;i++){
		pre[i]=pre[i-1]+(a[i]!=a[i+1]);
		sum[i]=sum[i-1]+(a[i]!=a[i+1]?f[i]:0);
		cnt[i]=cnt[i-1]+(a[i]!=a[i+1]?i:0);
	}
	for (LL i=1,j=1;i<=n;i++) if (a[i]!=a[i+1]){
		for (;j<=f[i]&&j<=n;j++) mn[j]=i;
	}
	ans=(r-l+1)*(m-1);
	ans+=(pre[r-1]-pre[l-1])*(r-l+1)*(m-1);
	ans+=(cnt[r-1]-cnt[l-1]);
	if (mn[r]<=l) ans-=r*(pre[r-1]-pre[l-1]);
	else ans=ans-r*(pre[r-1]-pre[mn[r]-1])-(sum[mn[r]-1]-sum[l-1]);
	printf("%lld\n",ans);
	
	return 0;
}