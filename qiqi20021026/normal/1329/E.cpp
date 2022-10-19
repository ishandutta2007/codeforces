#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
#define N 600000

LL n,m,k,a[N],b[N],f[N],g[N],pre[N],p[N];

bool cmp(LL x,LL y){return f[x]<f[y];}

void solve(){
	scanf("%lld%lld%lld",&m,&n,&k);
	for (LL i=1;i<=n;++i) scanf("%lld",a+i);
	k+=n+1;
	for (LL i=1;i<=n;++i) b[i]=a[i]-a[i-1];
	b[n+1]=m-a[n]; ++n;
	LL l=1,r=m,L,R;
	while (l<=r){
		LL mid=(l+r)>>1,sum=0;
		for (LL i=1;i<=n;++i) sum+=(b[i]+mid-1)/mid;
		if (sum<=k){R=mid; r=mid-1;}
		else l=mid+1;
	}
	l=1,r=m;
	for (LL i=1;i<=n;++i) r=min(r,b[i]);
	while (l<=r){
		LL mid=(l+r)>>1,sum=0;
		for (LL i=1;i<=n;++i) sum+=b[i]/mid;
		if (sum>=k){L=mid; l=mid+1;}
		else r=mid-1;
	}
	for (LL i=1;i<=n;++i){
		LL t=b[i]/L; g[i]=max(R,(b[i]+t-1)/t);
		t=(b[i]+R-1)/R; f[i]=min(L,b[i]/t);
		p[i]=i;
	}
	sort(p+1,p+n+1,cmp);
	pre[0]=R; for (LL i=1;i<=n;++i) pre[i]=max(pre[i-1],g[p[i]]);
	LL ans=pre[n]-L;
	for (LL i=n;i;--i) ans=min(ans,pre[i-1]-f[p[i]]);
	printf("%lld\n",ans);
}

int main(){
	LL t; scanf("%lld",&t);
	while (t--) solve();
	
	return 0;
}