#include<bits/stdc++.h>
using namespace std;

const int mod=1000000007;
int mi[500010],miu[10000010],t[10000010],n,x,ans,Ans,f[500010],g[500010];
bool bo[10000010];

int main()
{
	scanf("%d",&n),mi[0]=1;
	for (int i=1; i<=n; i++) mi[i]=(mi[i-1]+mi[i-1]>=mod?mi[i-1]+mi[i-1]-mod:mi[i-1]+mi[i-1]);
	for (int i=1; i<=n; i++) scanf("%d",&x),t[x]++;
	ans=1ll*(mi[n-1]-1)*n%mod;
	for (int i=2; i<=10000000; i++) miu[i]=1;
	for (int i=2; i<=10000000; i++) if (!bo[i])
		for (int j=i; j<=10000000; j+=i)
		{
			bo[j]=1,miu[j]=mod-miu[j];
			if (i<=10000&&j%(i*i)==0) miu[j]=0;
		}
	f[1]=n-1,g[1]=0;
	for (int i=2; i<=n; i++) f[i]=(2ll*f[i-1]-mi[i-1]+n+10ll*mod)%mod,g[i]=1ll*(mi[i-1]-1)*i%mod;
	Ans=f[n];
	for (int i=2; i<=10000000; i++)
	{
		x=0;
		for (int j=i; j<=10000000; j+=i) x+=t[j];
		ans=(ans+1ll*miu[i]*g[x])%mod;
		Ans=(Ans+1ll*miu[i]*f[x])%mod;
	}
	printf("%d\n",(ans-Ans+mod)%mod);
	return 0;
}