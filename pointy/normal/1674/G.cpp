// Author: Little09
// Problem: CF1674G Remove Directed Edges
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1674G
// Memory Limit: 250 MB
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
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m; 
int a[N],d[N],w[N];

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

vector<int>t[N];
inline void add(int x,int y)
{
	t[x].push_back(y);
	d[y]++,w[x]++;
}
queue<int>q;
int dfn[N],dp[N];
void topo()
{
	for (int i=1;i<=n;i++)
	{
		if (a[i]==0) q.push(i);
	}
	int cnt=0;
	while (!q.empty())
	{
		int u=q.front();
		q.pop();
		dfn[++cnt]=u;
		for (int i:t[u])
		{
			a[i]--;
			if (a[i]==0) q.push(i);
		}
	}
}

int main()
{
	n=read(),m=read();
	for (int i=1;i<=m;i++)
	{
		int x=read(),y=read();
		add(x,y);
	}
	for (int i=1;i<=n;i++) a[i]=d[i];
	topo();
	for (int i=n;i>=1;i--)
	{
		int u=dfn[i];
		dp[u]=1;
		for (int j:t[u])
		{
			if (d[j]>=2&&w[u]>=2) dp[u]=max(dp[u],dp[j]+1);
		}
	}
	int ans=0;
	for (int i=1;i<=n;i++) ans=max(ans,dp[i]);
	cout << ans;
	return 0;
}