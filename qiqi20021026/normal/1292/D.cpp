#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
#define N 5005
#define INF 0x3f3f3f3f3f3f3f3fLL

int n,m,x,f[N][N],g[N],h[N],cnt[N];
LL ans;

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		scanf("%d",&x); ++cnt[x];
	}
	m=5000;
	for (int i=1;i<=m;++i){
		memcpy(f[i],f[i-1],sizeof f[i]);
		g[i]=g[i-1];
		for (int j=2,x=i;j<=x;++j)
			while (x%j==0){x/=j; ++f[i][j]; ++g[i];}
		for (int j=i;j;--j)
			if (f[i][j]==f[i-1][j]) h[i]+=f[i][j];
			else{h[i]+=f[i-1][j]; break;}
	}
	ans=INF;
	for (int i=0;i<=m;++i){
		LL sum=0;
		for (int j=i-1,k=g[i];~j;--j){
			k=min(k,h[j+1]);
			sum+=(LL)(g[i]+g[j]-k*2)*cnt[j];
		}
		for (int j=i+1,k=g[i];j<=m;++j){
			k=min(k,h[j]);
			sum+=(LL)(g[i]+g[j]-k*2)*cnt[j];
		}
		ans=min(ans,sum);
		sum=0;
		for (int j=i-1,k=h[i];~j;--j){
			k=min(k,h[j+1]);
			sum+=(LL)(h[i]+g[j]-k*2)*cnt[j];
		}
		for (int j=i,k=h[i];j<=m;++j){
			k=min(k,h[j]);
			sum+=(LL)(h[i]+g[j]-k*2)*cnt[j];
		}
		ans=min(ans,sum);
	}
	printf("%lld\n",ans);
	
	return 0;
}