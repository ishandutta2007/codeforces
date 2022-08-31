#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef unsigned long long ull;
const int mod=998244353;
inline int addmod(int x)
{
	return x>=mod?x-mod:x;
}
inline int submod(int x)
{
	return x<0?x+mod:x;
}
int fpow(int x,int y)
{
	int ans=1;
	while(y)
	{
		if(y&1) ans=1ll*ans*x%mod;
		x=1ll*x*x%mod;
		y/=2;
	}
	return ans;
}
int lim,len,rev[1000005],w[2000005];
void getlim(int dep)
{
	lim=1,len=0;
	while(lim<=dep) lim<<=1,len++;
	for(int i=1;i<lim;i++)
		rev[i]=(rev[i>>1]>>1)|((i&1)<<(len-1));
}
ull tmp[1000005];
void ntt(int *a,int fl)
{
	for(int i=0;i<lim;i++)
		tmp[i]=a[rev[i]];
	for(int k=1;k<lim;k<<=1)
		for(int i=0;i<lim;i+=(k<<1))
			for(int j=0;j<k;j++)
			{
				int y=tmp[i+j+k]*w[j+k]%mod;
				tmp[i+j+k]=tmp[i+j]-y+mod;
				tmp[i+j]+=y;
			}
	for(int i=0;i<lim;i++)
		a[i]=tmp[i]%mod;
	if(fl==-1)
	{
		reverse(a+1,a+lim);
		int inv=fpow(lim,mod-2);
		for(int i=0;i<lim;i++)
			a[i]=1ll*a[i]*inv%mod;
	}
}
int n,k,f[1000005],g[1000005],fr[1000005],infr[1000005],pn=5e5;
int C(int x,int y)
{
	int mul=1;
	for(int i=x;i>x-y;i--)
		mul=1ll*mul*i%mod;
	return 1ll*mul*infr[y]%mod;
}
int main()
{
	for(int j=1;j<(1<<18);j<<=1)
	{
		int wn=fpow(3,(mod-1)/(j*2));
		w[j]=1;
		for(int i=1;i<j;i++)
			w[i+j]=1ll*w[i+j-1]*wn%mod;
	}
	fr[0]=infr[0]=1;
	for(int i=1;i<=pn;i++)
	{
		fr[i]=1ll*fr[i-1]*i%mod;
		infr[i]=fpow(fr[i],mod-2);
	}
	scanf("%d%d",&n,&k);
	getlim(2*k);
	for(int i=0;i<=k;i++)
		f[i]=1ll*fpow(i,k)*infr[i]%mod;
	for(int i=0;i<=k;i++)
		if(i%2==0) g[i]=infr[i];
		else g[i]=mod-infr[i];
	ntt(f,1);
	ntt(g,1);
	for(int i=0;i<lim;i++)
		f[i]=1ll*f[i]*g[i]%mod;
	ntt(f,-1);
	int ans=0,mul=1;
	for(int i=1;i<=min(n,k);i++)
	{
		mul=1ll*mul*(n-i+1)%mod;
		int nw=1ll*fpow((n+1)%mod,n-i)*mul%mod*infr[i]%mod;
		ans=addmod(ans+1ll*f[i]*fr[i]%mod*nw%mod);
	//	printf("i=%d,f=%d,nw=%d\n",i,f[i],nw);
	}
	printf("%d\n",ans);
	return 0;
}