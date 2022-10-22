// By: Little09
// Problem: E. William The Oblivious 
// Contest: Deltix Round, Autumn 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1609/problem/E
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

const ll inf=1000000000000000000; 
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m; 
int s[N];

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
int a[N],b[N],c[N],ab[N],bc[N],abc[N];

void push_up(int x)
{
	a[x]=a[x*2]+a[x*2+1];
	b[x]=b[x*2]+b[x*2+1];
	c[x]=c[x*2]+c[x*2+1];
	ab[x]=min(a[x*2]+ab[x*2+1],ab[x*2]+b[x*2+1]);
	bc[x]=min(b[x*2]+bc[x*2+1],bc[x*2]+c[x*2+1]);
	abc[x]=min(min(abc[x*2]+c[x*2+1],a[x*2]+abc[x*2+1]),ab[x*2]+bc[x*2+1]);
}
void build(int u,int l,int r)
{
	if (l==r)
	{
		a[u]=0,b[u]=0,c[u]=0,ab[u]=0,abc[u]=0,bc[u]=0;
		if (s[l]==0) a[u]=1;
		else if (s[l]==1) b[u]=1;
		else c[u]=1;
		return;
	}
	int mid=(l+r)>>1;
	build(u*2,l,mid);
	build(u*2+1,mid+1,r);
	push_up(u);
}
void update(int u,int l,int r,int x)
{
	if (l==r)
	{
		a[u]=0,b[u]=0,c[u]=0,ab[u]=0,abc[u]=0,bc[u]=0;
		if (s[l]==0) a[u]=1;
		else if (s[l]==1) b[u]=1;
		else c[u]=1;
		return;
	}
	int mid=(l+r)>>1;
	if (x<=mid) update(u*2,l,mid,x);
	else update(u*2+1,mid+1,r,x);
	push_up(u);
}
int main()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++) s[i]=readchar()-'a';
	build(1,1,n);
	for (int i=1;i<=m;i++)
	{
		int x=read(),y=readchar()-'a';
		s[x]=y;
		update(1,1,n,x);
		printf("%d\n",abc[1]);
	}
	return 0;
}