#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int mod=998244353,lim,len,rev[1000005];
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
void getlim(int x)
{
	lim=1,len=0;
	while(lim<=x) lim<<=1,len++;
	for(int i=1;i<lim;i++)
		rev[i]=(rev[i>>1]>>1)|((i&1)<<(len-1));
}
inline int addmod(int x)
{
	return x>=mod?x-mod:x;
}
inline int submod(int x)
{
	return x<0?x+mod:x;
}
void ntt(int *a,int fl)
{
	for(int i=0;i<lim;i++)
		if(i<rev[i]) swap(a[i],a[rev[i]]);
	for(int k=1;k<lim;k<<=1)
	{
		int wn=fpow(3,(mod-1)/(k*2));
		for(int i=0,r=k*2;i<lim;i+=r)
		{
			int w=1;
			for(int j=0;j<k;j++,w=1ll*w*wn%mod)
			{
				int x=a[i+j],y=1ll*a[i+j+k]*w%mod;
				a[i+j]=addmod(x+y);
				a[i+j+k]=submod(x-y);
			}
		}
	}
	if(fl==-1)
	{
		reverse(a+1,a+lim);
		int inv=fpow(lim,mod-2);
		for(int i=0;i<lim;i++)
			a[i]=1ll*a[i]*inv%mod;
	}
}
int c[1000005];
void getinv(int *a,int *b,int dep)
{
	if(dep==1)
	{
		b[0]=fpow(a[0],mod-2);
		return;
	}
	getinv(a,b,(dep+1)/2);
	getlim(2*dep);
	for(int i=0;i<dep;i++)
		c[i]=a[i];
	for(int i=dep;i<lim;i++)
		c[i]=0;
	ntt(c,1);
	ntt(b,1);
	for(int i=0;i<lim;i++)
		b[i]=1ll*submod(2-1ll*b[i]*c[i]%mod)*b[i]%mod;
	ntt(b,-1);
	for(int i=dep;i<lim;i++)
		b[i]=0; 
}
int da[1000005],db[1000005],ainv[1000005];
void getln(int *a,int *b,int dep)
{
	getlim(2*dep);
	for(int i=0;i<lim;i++)
		da[i]=db[i]=ainv[i]=0;
	for(int i=1;i<lim;i++)
		da[i-1]=1ll*a[i]*i%mod;
	da[lim-1]=0;
	getinv(a,ainv,dep);
	ntt(da,1);
	ntt(ainv,1);
	for(int i=0;i<lim;i++)
		db[i]=1ll*da[i]*ainv[i]%mod;
	ntt(db,-1);
	for(int i=0;i<lim-1;i++)
		b[i+1]=1ll*db[i]*fpow(i+1,mod-2)%mod;
	b[0]=0; 
}
int lnb[1000005],a1[1000005];
void getexp(int *a,int *b,int dep)
{
	if(dep==1)
	{
		b[0]=1;
		return;
	}
	getexp(a,b,(dep+1)/2);
	getlim(2*dep);
	for(int i=0;i<dep;i++)
		a1[i]=a[i];
	for(int i=dep;i<lim;i++)
		a1[i]=0;
	getln(b,lnb,dep);
	ntt(a1,1);
	ntt(b,1);
	ntt(lnb,1);
	for(int i=0;i<lim;i++)
		b[i]=1ll*b[i]*submod((1+a1[i])%mod-lnb[i])%mod;
	ntt(b,-1);
	for(int i=dep;i<lim;i++)
		b[i]=0;
	/*printf("lim=%d,b=",lim);
	for(int i=0;i<dep;i++)
		printf("%d ",b[i]);
	printf("\n");*/
}
int lna[1000005];
void getsqrt(int *a,int *b,int dep)
{
	getln(a,lna,dep);
	int inv=fpow(2,mod-2);
	for(int i=0;i<lim;i++)
		lna[i]=1ll*lna[i]*inv%mod;
	getexp(lna,b,dep);
}
int f[1000005],n,m,g[1000005],ans[1000005];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		f[x]=1;
	}
	m++;
	for(int i=0;i<=m;i++)
		f[i]=1ll*f[i]*(mod-4)%mod;
	f[0]=1;
	getsqrt(f,g,m);
	g[0]=(g[0]+1)%mod;
	getinv(g,ans,m);
	for(int i=1;i<m;i++)
		printf("%lld\n",2ll*ans[i]%mod);
	/*scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&f[i]);
	getsqrt(f,ans,n);
	for(int i=0;i<n;i++)
		printf("%d ",ans[i]); */
	return 0;
}