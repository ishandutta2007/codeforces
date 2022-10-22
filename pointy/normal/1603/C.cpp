// By: Little09
// Problem: CF1603C Extreme Extension
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1603C
// Memory Limit: 250 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))
const int N=1e5+5;
const ll mod=998244353;
int a[N],n;
ll dp[2][N];
vector<int>v[2];
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
void work()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	ll ans=0;
	int op=0;
	v[0].clear(),v[1].clear();
	for (int i=n;i>=1;i--)
	{
		dp[op][a[i]]=1;
		v[op].push_back(a[i]);
		for (int j=0;j<v[op^1].size();j++)
		{
			ll x=v[op^1][j],y=dp[op^1][x];
			if (dp[op^1][x]==0) continue;
			ll num=(a[i]+x-1)/x;
			ans=(ans+(num-1)*i%mod*y%mod)%mod;
			ll z=a[i]/num;
			dp[op][z]=(dp[op][z]+y)%mod;
			v[op].push_back(z);
			dp[op^1][x]=0;
		}
		v[op^1].clear();
		op^=1;
	}
	for (int j=0;j<v[op^1].size();j++) dp[op^1][v[op^1][j]]=0;
	v[op^1].clear();
	printf("%lld\n",ans);
}

int main()
{
	int T=read();
	while (T--) work();
	return 0;
}