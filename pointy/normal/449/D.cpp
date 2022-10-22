#include <bits/stdc++.h>
using namespace std;
const int N=3e6,M=20;
#define ll long long
const ll mod=1e9+7;
ll ksm(ll x,ll y)
{
	ll res=1;
	while (y)
	{
		if (y&1) res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
int n;
ll dp[N],f[N];
inline int read()
{
    int F=1,ANS=0;
	char C=getchar();
    while (C<'0'||C>'9')
	{
		if (C=='-') F=-1;
		C=getchar();
	}
    while (C>='0'&&C<='9')
	{
		ANS=ANS*10+C-'0';
		C=getchar();
	}
    return F*ANS;
}
ll ans=0;
int w(int x)
{
	int num=0;
	while (x)
	{
		if (x%2==1) num++;
		x>>=1;
	}
	if (num%2==1) return -1;
	return 1;
}
int main()
{
	n=read();
	for (int i=1;i<=n;i++) 
	{
		int x=read();
		dp[x]++;
	}
	for (int i=0;i<M;i++)
	{
		for (int j=(1<<M)-1;j>=0;j--)
		{
			if (!(j&(1<<i))) dp[j]=(dp[j]+dp[j^(1<<i)])%mod;
		}
	}
	for (int i=0;i<=(1<<M)-1;i++) f[i]=(ksm(2,dp[i])-1+mod)%mod;
	for (int i=0;i<=(1<<M)-1;i++) ans=(ans+w(i)*f[i]%mod+mod)%mod;
	cout << ans << endl;
	return 0;
}