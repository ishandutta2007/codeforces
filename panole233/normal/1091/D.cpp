#include<bits/stdc++.h>
using namespace std;

const int mod=998244353;
int n,ans,jc[1000001],inv[1000001];

int quickmi(int a,int b)
{
	int t=1;
	for (; b; b>>=1,a=1ll*a*a%mod)
		if (b&1) t=1ll*t*a%mod;
	return t;
}

int main()
{
	jc[0]=1;
	for (int i=1; i<=1000000; i++) jc[i]=1ll*i*jc[i-1]%mod;
	inv[1000000]=quickmi(jc[1000000],mod-2);
	for (int i=1000000; i; i--) inv[i-1]=1ll*i*inv[i]%mod;
 	scanf("%d",&n); ans=1;
	for (int i=0; i<n; i++)
		ans=(ans+1ll*jc[n]*inv[n-i]%mod*(jc[n-i]-1))%mod;
	printf("%d\n",ans);
	return 0;
}