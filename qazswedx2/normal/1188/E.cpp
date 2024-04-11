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
int n,a[100005],mx,f[1000005],cnt[1000005],fr[2000005],infr[2000005],pn=2e6;
inline int C(int x,int y)
{
	if(x<0||y<0||x<y) return 0;
	return 1ll*fr[x]*infr[y]%mod*infr[x-y]%mod;
}
int main()
{
	fr[0]=infr[0]=1;
	for(int i=1;i<=pn;i++)
		fr[i]=1ll*fr[i-1]*i%mod;
	infr[pn]=fpow(fr[pn],mod-2);
	for(int i=pn-1;i;i--)
		infr[i]=1ll*infr[i+1]*(i+1)%mod;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		mx=max(mx,a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		cnt[a[i]]++;
		for(int j=a[i];j<mx;j+=n)
			f[j]++;
	}
	for(int i=1;i<mx;i++)
	{
		cnt[i]+=cnt[i-1];
		f[i]+=f[i-1];
	}
	int ans=1;
	for(int i=0;i<mx;i++)
	{
		if(f[i]>=i+2) break;
		int q=i+1-f[i],q2=q-(n-cnt[i]);
		ans=addmod(ans+submod(C(q+n-1,n-1)-C(q2+n-1,n-1)));
	//	printf("i=%d,ans=%d\n",i,submod(C(q+n-1,n-1)-C(q2+n-1,n-1)));
	}
	printf("%d\n",ans);
	return 0;
}