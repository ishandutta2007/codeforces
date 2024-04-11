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
int n,m,a[1000005],b[1000005];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=n;i>0;i--)
		b[i]=(a[i]+b[i+1])%mod;
	for(int i=1;i<=m;i++)
	{
		int x,y,l,len;
		scanf("%d%d",&x,&y);
		l=lower_bound(a+1,a+n+1,y)-a;
		len=n-l+1;
		if(len<x) printf("0\n");
		else
		{
			int ans=1ll*b[l]*(len-x)%mod*fpow(len,mod-2)%mod;
			ans=addmod(ans+1ll*submod(b[1]-b[l])*(len-x+1)%mod*fpow(len+1,mod-2)%mod);
			printf("%d\n",ans);
		}
	}
	return 0;
}