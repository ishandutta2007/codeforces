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
int n,a[100005],fr[100005],infr[100005],pn=1e5,f[100005];
int A(int x,int y)
{
	if(x<0||y<0||x<y) return 0;
	return 1ll*fr[x]*infr[x-y]%mod;
}
int main()
{
	fr[0]=infr[0]=1;
	for(int i=1;i<=pn;i++)
	{
		fr[i]=1ll*fr[i-1]*i%mod;
		infr[i]=fpow(fr[i],mod-2);
	}
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	f[0]=1;
	for(int i=1;i<=n;i++)
	{
		int l=upper_bound(a+1,a+n+1,a[i]/2)-a-1;
		for(int j=0;j<i&&a[j]*2<=a[i];j++)
		{
			f[i]=addmod(f[i]+1ll*f[j]*A(n-j-1,l-j)%mod*A(i==n&&l==n-1?n-l-1:n-l-2,i-l-1)%mod);
	//		printf("i=%d,j=%d,qwq=%lld\n",i,j,1ll*f[j]*A(n-j-1,l-j)%mod*A(i==n&&l==n-1?n-l-1:n-l-2,i-l-1)%mod);
		}
	//	printf("i=%d,l=%d,f=%d\n",i,l,f[i]);
	}
	printf("%d\n",f[n]);
	return 0;
}