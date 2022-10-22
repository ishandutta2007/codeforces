// By: Little09
// Problem: D. X(or)-mas Tree
// Contest: Codeforces - Codeforces Global Round 18
// URL: https://codeforces.com/contest/1615/problem/D
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

const int N=500005;
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
int fa[N];
vector<int>t[N],v[N];
int find(int x)
{
	if (x==fa[x]) return fa[x];
	return fa[x]=find(fa[x]);
}
int wq[N];
bool ans;
inline int wr(int z)
{
	int res=0;
	while (z)
	{
		if (z&1) res^=1;
		z>>=1;
	}
	return res;
}
void merge(int x,int y)
{
	x=find(x),y=find(y);
	if (x==y) return;
	fa[x]=y;
}
void ddd(int x,int y,int z)
{
	if (z==0) 
	{
		if (find(x+n)==find(y)||find(y+n)==find(x))
		{
			ans=1;
			return;
		}
		merge(x,y),merge(x+n,y+n);
	}
	else
	{
		if (find(x)==find(y)||find(y+n)==find(x+n))
		{
			ans=1;
			return;
		}
		merge(x,y+n),merge(y,x+n);
	}
}
void dfs(int x,int f,int vv)
{
	if (x==1) a[x]=0,wq[find(1)]=0,wq[find(1+n)]=1;
	else 
	{
		if (wq[find(x)]==-1) 
		{
			a[x]=0;
			wq[find(x)]=0,wq[find(x+n)]=1;
		}
		else
		{
			a[x]=wq[find(x)];
		}
		if (vv!=-1) printf("%d %d %d\n",x,f,vv);
		else printf("%d %d %d\n",x,f,(a[x]^a[f]));
	}
	for (int i=0;i<t[x].size();i++)
	{
		if (t[x][i]==f) continue;
		dfs(t[x][i],x,v[x][i]);
	}
}
void work()
{
	n=read(),m=read(),ans=0;
	for (int i=1;i<=2*n;i++) fa[i]=i,wq[i]=-1;
	for (int i=1;i<=n;i++) t[i].clear();
	for (int i=1;i<=n;i++) v[i].clear();
	for (int i=1;i<n;i++)
	{
		int x=read(),y=read(),z=read();
		t[x].push_back(y),t[y].push_back(x);
		v[x].push_back(z),v[y].push_back(z);
		if (z!=-1) ddd(x,y,wr(z));
	}
	for (int i=1;i<=m;i++)
	{
		int x=read(),y=read(),z=read();
		ddd(x,y,z);
	}
	if (ans==1)
	{
		printNO;
		return;
	}
	a[1]=0;
	printYES;
	dfs(1,-1,-1);
	return;
}

int main()
{
	int T=read();
	while (T--) work();
	return 0;
}