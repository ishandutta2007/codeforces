// By: Little09
// Problem: D1. Game on Sum (Easy Version)
// Contest: Codeforces - Codeforces Round #767 (Div. 1)
// URL: https://codeforces.com/contest/1628/problem/D1
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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

const int N=2005;
int n,m,k; 
ll dp[N][N];
double p[N][N];

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
void work()
{
	n=read(),m=read(),k=read();
	dp[1][0]=0,dp[1][1]=k;
	p[1][0]=0,p[1][1]=k;
	ll tmp=ksm(2,mod-2);
	for (int i=2;i<=n;i++)
	{
		for (int j=0;j<=i;j++)
		{
			if (i==j)
			{
				dp[i][j]=(dp[i-1][j-1]+k)%mod;
			}
			else
			{
				dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])*tmp%mod;
			}
		}
	}
	cout << dp[n][m] << endl;
	return;
}

int main()
{
	int T=read();
	while (T--) work();
	return 0;
}