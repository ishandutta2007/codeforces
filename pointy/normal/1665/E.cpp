// By: Little09
// Problem: E. MinimizOR
// Contest: Codeforces - Codeforces Round #781 (Div. 2)
// URL: https://codeforces.com/contest/1665/problem/E
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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

const int inf=2000000000; 
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=100005;
int n,m; 

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

int a[N],b[N],c[N];
struct point
{
	int x;
	bool operator < (const point & o) const
	{
		return a[x]<a[o.x];
	}
}sum[N*4];
inline void push_up(int u)
{
	sum[u]=min(sum[u*2],sum[u*2+1]);
}
void build(int u,int l,int r)
{
	if (l==r)
	{
		sum[u].x=l;
		return;
	}
	int mid=(l+r)>>1;
	build(u*2,l,mid);
	build(u*2+1,mid+1,r);
	push_up(u);
}
point ask(int u,int L,int R,int l,int r)
{
	if (l<=L&&R<=r) return sum[u];
	int mid=(L+R)>>1;
	point res;
	res.x=n+1;
	if (l<=mid) res=min(res,ask(u*2,L,mid,l,r));
	if (mid<r) res=min(res,ask(u*2+1,mid+1,R,l,r));
	return res;
}
void change(int u,int l,int r,int x)
{
	if (l==r) return;
	int mid=(l+r)>>1;
	if (x<=mid) change(u*2,l,mid,x);
	else change(u*2+1,mid+1,r,x);
	push_up(u);
}

void work()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=read(),c[i]=a[i];
	build(1,1,n);
	m=read();
	a[n+1]=inf;
	for (int i=1;i<=m;i++)
	{
		int l=read(),r=read(),cnt=0;
		for (int k=29;k>=-1;k--)
		{
			int u=ask(1,1,n,l,r).x;
			int tmp=a[u];
			a[u]=inf;
			change(1,1,n,u);
			int v=ask(1,1,n,l,r).x;
			a[u]=tmp;
			change(1,1,n,u);
			if (k==-1)
			{
				printf("%d\n",(a[u]|a[v]));
				break;
			}
			if ((!(a[u]&(1<<k)))&&(a[v]&(1<<k))) 
			{
				a[u]=tmp+(1<<k);
				change(1,1,n,u);
				b[++cnt]=u;
			}
		}
		for (int i=1;i<=cnt;i++)
		{
			a[b[i]]=c[b[i]];
			change(1,1,n,b[i]);
		}
	}
}

int main()
{
	int T=read();
	while (T--) work();
	return 0;
}