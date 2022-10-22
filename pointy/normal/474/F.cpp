// By: Little09
// Problem: CF474F Ant colony
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF474F
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

int gcd(int x,int y)
{
	return y?gcd(y,x%y):x;
}

int w[N];

struct point
{
	int r,g,sum;
}a[N*4];

inline point push_up(point u,point v)
{
	point res;
	res.r=min(u.r,v.r);
	res.g=gcd(u.g,v.g);
	res.sum=0;
	if (u.r==res.r) res.sum+=u.sum;
	if (v.r==res.r) res.sum+=v.sum;
	return res;
}
void build(int u,int l,int r)
{
	if (l==r) 
	{
		a[u].r=w[l],a[u].g=w[l],a[u].sum=1;
		return;
	}
	int mid=(l+r)>>1;
	build(u*2,l,mid),build(u*2+1,mid+1,r);
	a[u]=push_up(a[u*2],a[u*2+1]);
}
point ask(int u,int L,int R,int l,int r)
{
	if (l<=L&&R<=r) return a[u];
	int mid=(L+R)>>1;
	point res=(point){1000000000,0,0};
	if (l<=mid) res=push_up(res,ask(u*2,L,mid,l,r));
	if (mid<r) res=push_up(res,ask(u*2+1,mid+1,R,l,r));
	return res;
}

int main()
{
	n=read();
	for (int i=1;i<=n;i++) w[i]=read();
	build(1,1,n);
	m=read();
	for (int i=1;i<=m;i++)
	{
		int l=read(),r=read();
		point res=ask(1,1,n,l,r);
		if (res.r==res.g) printf("%d\n",r-l+1-res.sum);
		else printf("%d\n",r-l+1);
	}
	return 0;
}