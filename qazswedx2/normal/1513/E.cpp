#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
inline int fpow(int x,int y)
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
int n,a[1000005],fr[1000005],infr[1000005],pn=1e5;
ll sum;
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
		sum+=a[i];
	}
	if(sum%n)
	{
		printf("0\n");
		return 0;
	}
	sum/=n;
	sort(a+1,a+n+1);
	int ct0=0,ct1=0;
	for(int i=1;i<=n;i++)
	{
		ct0+=(a[i]<sum);
		ct1+=(a[i]>sum);
	}
	int ans=1;
	for(int l=1,r;l<=n;l=r+1)
	{
		r=l;
		while(r<n&&a[r+1]==a[l]) r++;
		ans=1ll*ans*infr[r-l+1]%mod;
	}
	if(ct0<=1||ct1<=1)
	{
		ans=1ll*ans*fr[n]%mod;
		printf("%d\n",ans);
		return 0;
	}
	ans=1ll*ans*fr[n]%mod*infr[ct0+ct1]%mod*fr[ct1]%mod*fr[ct0]%mod;
	if(ct0&&ct1) ans=2*ans%mod;
	printf("%d\n",ans);
	return 0;
}