// Author: Little09
// Problem: CF1336C Kaavi and Magic Spell
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1336C
// Memory Limit: 500 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=998244353;
const int N=3005;
char a[N],b[N];
int n,m;
int dp[N][N];
bool check(int x,int y)
{
	if (y>m) return 1;
	return (a[x]==b[y]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> (a+1) >> (b+1);
	n=strlen(a+1),m=strlen(b+1);
	for (int i=1;i<=n;i++) dp[i][i]=check(1,i)*2;
	for (int l=2;l<=n;l++)
	{
		for (int i=1;i<=n-l+1;i++)
		{
			int j=i+l-1;
			dp[i][j]=(dp[i][j-1]*check(l,j)+dp[i+1][j]*check(l,i))%mod;
		}
	}
	ll ans=0;
	for (int i=m;i<=n;i++) ans=(ans+dp[1][i])%mod;
	cout << ans << endl;
	return 0;
}