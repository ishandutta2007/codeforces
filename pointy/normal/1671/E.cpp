// Author: Little09
// Problem: CF1671E Preorder
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1671E
// Memory Limit: 500 MB
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
#define endl "\n"
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m; 
char a[N];
string s[N];
ll dp[N];

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

void dfs(int u)
{
	if (u>=(1<<(n-1)))
	{
		s[u]=a[u];
		dp[u]=1;
		return;
	}
	dfs(u*2),dfs(u*2+1);
	if (s[u*2]==s[u*2+1]) dp[u]=dp[u*2]*dp[u*2+1]%mod;
	else dp[u]=2ll*dp[u*2]%mod*dp[u*2+1]%mod;
	s[u]=a[u];
	if (s[u*2]>s[u*2+1]) s[u]+=s[u*2+1]+s[u*2];
	else s[u]+=s[u*2]+s[u*2+1];
}

int main()
{
	n=read();
	for (int i=1;i<(1<<n);i++) a[i]=readchar();
	dfs(1);
	cout << dp[1];
	return 0;
}