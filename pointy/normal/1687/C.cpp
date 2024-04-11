// By: Little09
// Problem: CF1687C Sanae and Giant Robot
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1687C
// Memory Limit: 250 MB
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
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m; 
ll a[N];
vector<int>b[N];

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
int find(int x)
{
	if (x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void ddd(int l,int r)
{
	if (a[l]!=0||a[r]!=0) return;
	if (l>r) swap(l,r);
	while (1)
	{
		r=find(r);
		if (r<=l) break;
		fa[r]=r-1,a[r]=0;
		for (int j:b[r])
		{
			ddd(r,j);
		}
	}
}
void work()
{
	n=read(),m=read();
	for (int i=0;i<=n;i++) b[i].clear();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++) a[i]-=read();
	for (int i=2;i<=n;i++) a[i]+=a[i-1];
	for (int i=1;i<=m;i++)
	{
		int x=read(),y=read();
		x--;
		b[x].push_back(y);
		b[y].push_back(x);
	}
	for (int i=0;i<=n;i++) fa[i]=i;
	for (int i=1;i<=n;i++)
	{
		if (a[i]==0)
		{
			fa[i]=i-1;
			for (int j:b[i])
			{
				ddd(i,j);
			}
		}
	}
	int u=find(n);
	if (u==0) printYES;
	else printNO;
	
}

int main()
{
	int T=read();
	while (T--) work();
	return 0;
}