#include <bits/stdc++.h>
#define fo(i,a,b) for(register LL i=a;i<=b;++i)
#define fd(i,a,b) for(register LL i=a;i>=b;--i)
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define LL long long
#define mo 998244353
#define N 500005
using namespace std;
inline LL read()
{
   	LL X=0,w=0;char ch=0;
    while(!isdigit(ch)){w|=ch=='-';ch=getchar();}
    while(isdigit(ch)) X=(X<<3)+(X<<1)+(ch^48),ch=getchar();
    return w?-X:X;
}
LL ne[N],he[N],la[N],ind[N],a[N],aa[N],d[N],tot=0,po[N];
bool vis[N];
LL f[N],sum[N],su[N];
inline void lb(LL x,LL y)
{
	ne[++tot]=he[x];
	la[he[x]=tot]=y;
	ind[x]++;
}
inline void dg(LL x)
{
	vis[po[++tot]=x]=1;
	for(register LL ii=he[x];ii;ii=ne[ii])if(!vis[la[ii]])dg(la[ii]);
}
inline LL getline(LL x)
{
	tot=0;
	dg(x);
	f[0]=(tot%2?-1:1);
	LL en=1;
	d[en]=0;
	sum[0]=f[0];
	fo(i,1,tot)
	{
		f[i]=0;
		a[i]=aa[po[i]];
		while(a[d[en]]>=a[i])en--;
		f[i]=(f[i]+(sum[i-1]-sum[d[en]]+f[d[en]])%mo*a[i]*(-1)%mo)%mo;
		f[i]=(f[i]+su[en])%mo;
		d[++en]=i;
		su[en]=(sum[i-1]-sum[d[en-1]]+f[d[en-1]])%mo*a[i]*(-1)%mo;
		su[en]=(su[en-1]+su[en])%mo;
		sum[i]=(sum[i-1]+f[i])%mo;
	}
	return (f[tot]%mo+mo)%mo;
}
int main()
{
//	freopen("rainbow.in","r",stdin);
//	freopen("rainbow.out","w",stdout);
	LL n=read();
	fo(i,1,n)aa[i]=read();
	fo(i,1,n-1)lb(i,i+1);
	LL ans=1;
	fo(i,1,n)if(!vis[i]&&ind[i]<2)ans=ans*getline(i)%mo;
	printf("%lld\n",ans);
	return 0;
}