#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
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
int lim,len,rev[1000005];
void getlim(int x)
{
	lim=1,len=0;
	while(lim<=x) lim<<=1,len++;
	for(int i=1;i<lim;i++)
		rev[i]=(rev[i>>1]>>1)|((i&1)<<(len-1));
}
void ntt(int *a,int fl)
{
	for(int i=1;i<lim;i++)
		if(i<rev[i]) swap(a[i],a[rev[i]]);
	for(int k=1;k<lim;k<<=1)
	{
		int wn=fpow(3,(mod-1)/(k*2));
		for(int i=0,r=k*2;i<lim;i+=r)
		{
			int w=1;
			for(int j=0;j<k;j++,w=1ll*w*wn%mod)
			{
				int x=a[i+j],y=1ll*w*a[i+j+k]%mod;
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
int n,f[1000005],g[1000005],fr[1000005],infr[1000005],a[1000005],pn=2e5;
ll m;
int main()
{
	fr[0]=infr[0]=1;
	for(int i=1;i<=pn;i++)
	{
		fr[i]=1ll*fr[i-1]*i%mod;
		infr[i]=fpow(fr[i],mod-2);
	}
	scanf("%d%lld",&n,&m);
	n++;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&f[i]);
		f[i]=1ll*f[i]*fr[i]%mod; 
	}
	for(int i=0;i<n;i++)
		a[i]=infr[i];
	reverse(f,f+n);
	/*for(int i=0;i<n;i++)
		printf("%d ",f[i]);
	printf("\n");
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");*/
	getlim(2*n);
	ntt(f,1);
	ntt(a,1);
	for(int i=0;i<lim;i++)
		g[i]=1ll*f[i]*a[i]%mod;
	ntt(g,-1);
	for(int i=n;i<lim;i++)
		g[i]=0;
	reverse(g,g+n);
	for(int i=0;i<n;i++)
	{
		g[i]=1ll*g[i]*fpow(i+1,1ll*(mod-2)*(m%(mod-1))%(mod-1))%mod;
	//	printf("i=%d,f=%d\n",i,fpow(i+1,1ll*(mod-2)*(m%(mod-1))%(mod-1)));
	}
//	for(int i=0;i<n;i++)
//		printf("%d ",g[i]);
//	printf("\n");
	reverse(g,g+n);
	memset(a,0,sizeof(a));
	for(int i=0;i<n;i++)
		if(i%2==0) a[i]=infr[i];
		else a[i]=mod-infr[i];
	ntt(g,1);
	ntt(a,1);
	for(int i=0;i<lim;i++)
		f[i]=1ll*g[i]*a[i]%mod;
	ntt(f,-1);
	reverse(f,f+n);
	for(int i=0;i<n;i++)
		f[i]=1ll*infr[i]*f[i]%mod;
	for(int i=0;i<n;i++)
		printf("%d ",f[i]);
	return 0;
}