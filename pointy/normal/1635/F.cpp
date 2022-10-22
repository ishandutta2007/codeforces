// By: Little09
// Problem: CF1635F Closest Pair
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1635F
// Memory Limit: 250 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
const int N=3e5+5;
const ll inf=4001000000000000000;
ll a[N],b[N],ans[N];
struct point
{
	int id,x;
};
vector<point>q[N];
ll s[N*4];
inline void push_up(int u)
{
	s[u]=min(s[u*2],s[u*2+1]);
}
void build(int u,int l,int r)
{
	s[u]=inf;
	if (l==r) return;
	int mid=(l+r)>>1;
	build(u*2,l,mid);
	build(u*2+1,mid+1,r);
}
void update(int u,int l,int r,int x,ll k)
{
	if (l==r)
	{
		s[u]=min(s[u],k);
		return;
	}
	int mid=(l+r)>>1;
	if (x<=mid) update(u*2,l,mid,x,k);
	else update(u*2+1,mid+1,r,x,k);
	push_up(u);
}
ll ask(int u,int L,int R,int l,int r)
{
	if (l<=L&&R<=r) return s[u];
	int mid=(L+R)>>1;
	ll res=inf;
	if (l<=mid) res=min(res,ask(u*2,L,mid,l,r));
	if (mid<r) res=min(res,ask(u*2+1,mid+1,R,l,r));
	return res;
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
int st[N],top;

int main()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++) a[i]=read(),b[i]=read();
	for (int i=1;i<=m;i++)
	{
		int l=read(),r=read();
		q[r].push_back((point){i,l});
	}
	build(1,1,n);
	for (int i=1;i<=n;i++)
	{
		while (top!=0&&b[st[top]]>=b[i]) 
		{
			update(1,1,n,st[top],(a[i]-a[st[top]])*(b[i]+b[st[top]]));
			top--;
		}
		if (top!=0) update(1,1,n,st[top],(a[i]-a[st[top]])*(b[i]+b[st[top]]));
		st[++top]=i;
		for (point j:q[i])
		{
			ans[j.id]=ask(1,1,n,j.x,i);
		}
	}
	for (int i=1;i<=m;i++) printf("%lld\n",ans[i]);
	return 0;
}