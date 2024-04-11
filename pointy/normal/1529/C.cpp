// Author: Little09
// Problem: C. Parsa's Humongous Tree
// Contest: Codeforces Round #722 (Div. 2)
// URL: https://codeforces.com/contest/1529/problem/C
// Memory Limit: 256 MB
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
#define endl "\n"
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m; 
ll l[N],r[N],dp[N][2];

vector<int>t[N];

void add(int x,int y)
{
	t[x].push_back(y);
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


void dfs(int x,int fa)
{
	for (int i:t[x])
	{
		if (i==fa) continue;
		dfs(i,x);
		dp[x][0]+=max(dp[i][0]+abs(l[x]-l[i]),dp[i][1]+abs(l[x]-r[i]));
		dp[x][1]+=max(dp[i][0]+abs(r[x]-l[i]),dp[i][1]+abs(r[x]-r[i]));
	}
}
void work()
{
	n=read();
	for (int i=1;i<=n;i++) l[i]=read(),r[i]=read(),dp[i][0]=dp[i][1]=0;
	for (int i=1;i<=n;i++) t[i].clear();
	for (int i=1;i<n;i++)
	{
		int x=read(),y=read();
		add(x,y),add(y,x);
	}
	dfs(1,0);
	cout << max(dp[1][0],dp[1][1]) << endl;
}

int main()
{
	int T=read();
	while (T--) work();
	return 0;
}