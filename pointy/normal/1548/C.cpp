// By: Little09
// Problem: C. The Three Little Pigs
// Contest: Codeforces - Codeforces Round #736 (Div. 1)
// URL: https://codeforces.com/contest/1548/problem/C
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))
#define printYes puts("Yes")
#define printYES puts("YES")
#define printNo puts("No")
#define printNO puts("NO")

const ll inf=1000000000000000000; 

//const ll mod=998244353;
const ll mod=1000000007;
int n,q;
const int N=3000005;
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
ll jc[N+5],inv[N+5];
ll dp[N][3];
inline ll C(ll x,ll y)
{
	if (y>x) return 0;
	return jc[x]*inv[y]%mod*inv[x-y]%mod;
}
void init()
{
	jc[0]=1;
	for (int i=1;i<=N;i++) jc[i]=jc[i-1]*i%mod;
	inv[N]=ksm(jc[N],mod-2);
	for (int i=N-1;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
}

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
inline char readchar()
{
	char C=getchar();
    while (C<33||C>126) C=getchar();
    return C;
}
inline int raed(){return read();}

int main()
{
	n=read(),q=read();
	init();
	dp[0][0]=dp[0][1]=dp[0][2]=n;
	ll tmp=ksm(3,mod-2);
	for (int i=1;i<=3*n;i++)
	{
		dp[i][2]=(C(3*n,i+1)+dp[i-1][0]+dp[i-1][1]*2ll)%mod*tmp%mod;
		dp[i][1]=(dp[i][2]-dp[i-1][1]+mod)%mod;
		dp[i][0]=(dp[i][1]-dp[i-1][0]+mod)%mod;
	}
	while (q--)
	{
		int x=read();
		ll ans=dp[x][0]+C(3*n,x);
		printf("%lld\n",ans%mod);
	}
	return 0;
}