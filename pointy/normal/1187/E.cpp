// By: Little09
// Problem: CF1187E Tree Painting
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1187E
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
int h[N],t[N],nxt[N],cnt,size[N];
ll ans[N];
void add(int x,int y)
{
	t[++cnt]=y;
	nxt[cnt]=h[x];
	h[x]=cnt;
}
void dfs1(int x,int fa)
{
	size[x]=1;
	for (int i=h[x];i;i=nxt[i])
	{
		if (t[i]!=fa)
		{
			dfs1(t[i],x);
			size[x]+=size[t[i]];
		}
	}
}
void dfs2(int x,int fa)
{
	if (fa!=0)
	{
		ans[x]=ans[fa]-size[x]+n-size[x];
	}
	for (int i=h[x];i;i=nxt[i])
	{
		if (t[i]!=fa)
		{
			dfs2(t[i],x);
		}
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

void work()
{
	n=read();
	for (int i=1;i<n;i++)
	{
		int x=read(),y=read();
		add(x,y),add(y,x);
	}
	dfs1(1,0);
	for (int i=1;i<=n;i++) ans[1]+=size[i];
	dfs2(1,0);
	ll res=ans[1];
	for (int i=2;i<=n;i++) res=max(res,ans[i]);
	cout << res;
	return;
}

int main()
{
	int tp=1;
	//0 : many test cases
	//1 : one test case
	if (tp==0) T=read();
	else T=1;
	while (T--)
	{
		work();
	}
	return 0;
}