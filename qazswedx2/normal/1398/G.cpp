#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
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
int n,X,Y,a[200005],m,f[1000005],g[1000005];
int q[1000005],pn=1e6;
int main()
{
	scanf("%d%d%d",&n,&X,&Y);
	for(int i=0;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<=n;i++)
		f[a[i]]=1,g[X-a[i]]=1;
	getlim(2*X+2);
	ntt(f,1);
	ntt(g,1);
	for(int i=0;i<lim;i++)
		f[i]=1ll*f[i]*g[i]%mod;
	ntt(f,-1);
	for(int i=X+1;i<=2*X;i++)
		if(f[i]) q[i-X+Y]=i-X+Y;
	for(int i=1;i<=pn;i++)
		for(int j=i;j<=pn;j+=i)
			q[j]=max(q[j],q[i]);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		int x;
		scanf("%d",&x);
		x/=2;
		if(!q[x])
		{
			printf("-1 ");
			continue;
		}
		printf("%d ",q[x]*2);
	}
	return 0;
}