// By: Little09
// Problem: D. Social Network
// Contest: Deltix Round, Autumn 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1609/problem/D
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
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m; 
int a[N],c[N];
vector<int>t[N];
bool used[N];
int ans,res;
void dfs(int x)
{
	if (used[x]) return;
	res++;
	used[x]=1;
	for (int u:t[x]) dfs(u);
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

int fa[N];

int find(int x)
{
	if (fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}

int main()
{
	n=read(),m=read();
	int tot=1;
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<=m;i++)
	{
		int x=read(),y=read();
		if (find(x)==find(y))
		{
			tot++;
		}
		fa[find(x)]=find(y);
		t[x].push_back(y);
		t[y].push_back(x);
		for (int j=1;j<=n;j++) used[j]=0;
		ans=0;
		int u=0;
		for (int j=1;j<=n;j++)
		{
			if (used[j]==1) continue;
			res=0;
			dfs(j);
			c[++u]=res;
		}
		sort(c+1,c+u+1);
		for (int i=u;i>=u-tot+1;i--) ans+=c[i];
		cout << ans-1 << endl;
	}
	return 0;
}