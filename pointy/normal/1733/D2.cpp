// Author: Little09
// Problem: D2. Zero-One (Hard Version)
// Contest: Codeforces - Codeforces Round #821 (Div. 2)
// URL: https://codeforc.es/contest/1733/problem/D2
// Memory Limit: 512 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))
#define printYes cout << "Yes" << endl
#define printYES cout << "YES" << endl
#define printNo cout << "No" << endl
#define printNO cout << "NO" << endl
#define endl "\n"
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll inf=1000000000;
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=5005;
int n;
ll x,y; 
char a[N],b[N];
int c[N],pre[N];
ll dp[N][N];

int cnt;

void work()
{
	cin >> n >> x >> y;
	for (int i=1;i<=n;i++) cin >> a[i];
	for (int i=1;i<=n;i++) cin >> b[i];
	cnt=0;
	int s=0,p=0;
	for (int i=1;i<=n;i++) c[i]=(a[i]!=b[i]),s+=c[i];
	for (int i=2;i<=n;i++) 
	{
		if (c[i]==1&&c[i-1]==1) p++,i++;
	}
	int las=-1;
	for (int i=1;i<=n;i++)
	{
		pre[i]=0;
		if (c[i]==0) continue;
		if (las!=-1) pre[i]=las;
		las=i;
	}
	if (s&1)
	{
		cout << -1 << endl;
		return;
	}
	if (x>=y)
	{
		x=min(x,2*y);
		if (s==0) cout << 0 << endl;
		else if (s==2&&p==1) cout << x << endl;
		else cout << 1ll*s/2*y << endl;	
	}
	else
	{
		for (int i=0;i<=n;i++)
		{
			for (int j=0;j<=n;j++)
			{
				dp[i][j]=inf;
			}
			dp[i][0]=0;
		}
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=i;j++)
			{
				dp[i][j]=dp[i-1][j];
				if (pre[i]!=0) dp[i][j]=min(dp[i][j],dp[pre[i]-1][j-1]+x*(i-pre[i]));
			}
		}
		ll ans=inf;
		for (int i=0;i<=s/2;i++) ans=min(ans,dp[n][i]+(s/2-i)*y);
		cout << ans << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while (T--) work();
	return 0;
}