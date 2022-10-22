// By: Little09
// Problem: CF1249F Maximum Weight Subset
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1249F
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
#define clear(x,y,z); for (int o=0;o<=y;o++) x[o]=z;

const ll inf=1000000000000000000; 
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m,T; 
int a[N];

int h[N],t[N],nxt[N],cnt,ans;
void add(int x,int y)
{
	t[++cnt]=y;
	nxt[cnt]=h[x];
	h[x]=cnt;
}
void change(int x,int fa,int dis,int y)
{
	if (dis>m) return;
	a[x]-=y;
	for (int i=h[x];i;i=nxt[i])
	{
		if (t[i]!=fa) change(t[i],x,dis+1,y);
	}
}
vector<int>q[N];
void dfs(int x,int fa,int dis)
{
	q[dis].push_back(x);
	for (int i=h[x];i;i=nxt[i])
	{
		if (t[i]!=fa) dfs(t[i],x,dis+1);
	}
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
	n=read(),m=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<n;i++)
	{
		int x=read(),y=read();
		add(x,y),add(y,x);
	}
	dfs(1,0,1);
	for (int i=n;i>=1;i--)
	{
		for (int j=0;j<q[i].size();j++)
		{
			if (a[q[i][j]]>0)
			{
				ans+=a[q[i][j]];
				change(q[i][j],0,0,a[q[i][j]]);
			}
		}
	}
	cout << ans << endl;
	return 0;
}