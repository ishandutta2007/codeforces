#include<bits/stdc++.h>
using namespace std;

const int N=124750;
int f[N+5],mod,n,jc[510],sum[N+5],ans,summ1[N+5],summ2[N+5];

int add(int x,int y) {return x+y>=mod?x+y-mod:x+y;}

int main()
{
	scanf("%d%d",&n,&mod);
	jc[0]=1;
	for (int i=1; i<=n; i++) jc[i]=1ll*jc[i-1]*(n-i+1)%mod;
	f[0]=sum[0]=summ1[0]=1;
	for (int i=1; i<n; i++)
	{
		int nw=0,N=(i-1)*i/2;
		for (int j=2; j<=N; j++) nw=(nw+(1ll*(i+1-j+1)*(summ1[j-2]-(j-i-2<0?0:summ1[j-i-2]))+summ2[j-2]-(j-i-2<0?0:summ2[j-i-2]))%mod*f[j])%mod;
		ans=(ans+1ll*(nw+mod)*jc[n-i-1])%mod;
		for (int j=N+1; j<=N+i; j++) sum[j]=sum[j-1];
		for (int j=0; j<=N+i; j++) f[j]=add(sum[j],j-i-1<0?0:mod-sum[j-i-1]);
		summ1[0]=sum[0]=f[0],summ2[0]=0;
		for (int j=1; j<=N+i; j++) sum[j]=add(f[j],sum[j-1]),summ1[j]=add(summ1[j-1],sum[j]),summ2[j]=(summ2[j-1]+1ll*j*sum[j])%mod;
	}
	printf("%d\n",ans);
	return 0;
}

//n=i+1
//f[j]*(sum[j-2]*(n-1)+...+sum[j-n]*1)
//f[j]*(sigma k=2..n  sum[j-k]*(j-k)+sum[j-k]*(n-j+1))
//N=i*(i-1)/2
//sum[0]..sum[N-n] n*(n-1)/2
//sum[