// By: Pointy
// Problem: B. And It's Non-Zero
// Contest: Codeforces - Codeforces Global Round 18
// URL: https://codeforces.com/contest/1615/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
//const ll mod=1000000007;

const int N=200005;
int n,m; 
int a[N];

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
int dp[N][21];
void work()
{
	int l=read(),r=read();
	int len=r-l+1,ans=0;
	for (int i=0;i<=20;i++)
	{
		ans=max(ans,dp[r][i]-dp[l-1][i]);
	}
	cout << len-ans << endl;
	return;
}

int main()
{
	for (int i=1;i<=2e5;i++)
	{
		for (int j=0;j<=20;j++)
		{
			if (i&(1<<j)) dp[i][j]=dp[i-1][j]+1;
			else dp[i][j]=dp[i-1][j];
		}
	}
	int T=read();
	while (T--) work();
	return 0;
}