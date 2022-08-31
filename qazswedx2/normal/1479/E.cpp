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
int n,m,a[1005],c,f,g;
int main()
{
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
		scanf("%d",&a[i]),n+=a[i];
	sort(a+1,a+m+1);
	f=2;
	c=2;
	g=1;
	int nw=1,ans=0;
	while(nw<=m&&a[nw]==1)
	{
		ans=submod(ans-1ll*c*fpow(g,mod-2)%mod);
		nw++;
	}
	for(int i=1;i<n;i++)
	{
		f=1ll*f*(2*n-i)%mod;
		c=addmod(1ll*c*(n-i)%mod+f);
		g=1ll*g*(n-i)%mod;
		while(nw<=m&&a[nw]==i+1)
		{
			ans=submod(ans-1ll*c*fpow(g,mod-2)%mod);
			nw++;
		}
	}
	ans=addmod(ans+1ll*c*fpow(g,mod-2)%mod);
	printf("%d\n",ans);
	return 0;
}