#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
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
int b[15],m=6,pn=1e6;
void solve(int *a)
{
	for(int i=0;i<6;i++)
		for(int j=pn-1;j>=0;j--)
			if(j/b[i]%10!=9)
				a[j]=addmod(a[j]+a[j+b[i]]);
}
void solvei(int *a)
{
	for(int i=0;i<6;i++)
		for(int j=0;j<pn;j++)
			if(j/b[i]%10!=9)
				a[j]=submod(a[j]-a[j+b[i]]);
}
int n,a[1000005],f[3][1000005],tans[1000005];
int main()
{
	b[0]=1;
	for(int i=1;i<m;i++)
		b[i]=b[i-1]*10;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		f[0][a[i]]++;
		f[1][a[i]]=addmod(f[1][a[i]]+a[i]);
		f[2][a[i]]=addmod(f[2][a[i]]+1ll*a[i]*a[i]%mod);
	}
	solve(f[0]);
	solve(f[1]);
	solve(f[2]);
	for(int i=0;i<pn;i++)
	{
		if(!f[0][i]) continue;
		if(f[0][i]==1)
		{
			tans[i]=f[2][i];
			continue;
		}
		tans[i]=1ll*fpow(2,f[0][i]-2)*addmod(1ll*f[1][i]*f[1][i]%mod+f[2][i])%mod;
	}
	solvei(tans);
//	for(int i=0;i<pn;i++)
//		if(tans[i])
//			printf("i=%d,tans=%lld\n",i,1ll*i*tans[i]);
	ll ans=0;
	for(int i=0;i<pn;i++)
		ans^=1ll*i*tans[i];
	printf("%lld\n",ans);
	return 0;
}