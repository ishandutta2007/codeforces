// Author: Little09
// Problem: CF1404C Fixed Point Removal
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1404C
// Memory Limit: 250 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
const int N=3e5+5;
int a[N],n,m,ans[N];
struct point
{
	int id,l;
};
vector<point>q[N];
int s[N*4],add[N*4];
inline void push_up(int u)
{
	s[u]=min(s[u*2],s[u*2+1]);
}
inline void push_down(int u)
{
	if (add[u]==0) return;
	add[u*2]+=add[u],s[u*2]+=add[u];
	add[u*2+1]+=add[u],s[u*2+1]+=add[u];
	add[u]=0;
}
void build(int u,int l,int r)
{
	if (l==r)
	{
		s[u]=-1,add[u]=0;
		return;
	}
	int mid=(l+r)>>1;
	build(u*2,l,mid),build(u*2+1,mid+1,r);
	push_up(u);
}
void update(int u,int l,int r,int x)
{
	if (l==r)
	{
		s[u]=0;
		return;
	}
	int mid=(l+r)>>1;
	push_down(u);
	if (x<=mid) update(u*2,l,mid,x);
	else update(u*2+1,mid+1,r,x);
	push_up(u);
}
void change(int u,int l,int r,int k)
{
	if (l==r)
	{
		if (s[u]>=k) s[u]++;
		return;
	}
	int mid=(l+r)>>1;
	push_down(u);
	if (s[u*2]>=k)
	{
		add[u*2]++,s[u*2]++;
		change(u*2+1,mid+1,r,k);
	}
	else change(u*2,l,mid,k);
	push_up(u);
}
int ask(int u,int l,int r,int x)
{
	if (l==r) return s[u];
	push_down(u);
	int mid=(l+r)>>1;
	if (x<=mid) return ask(u*2,l,mid,x);
	return ask(u*2+1,mid+1,r,x);
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

int main()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++)
	{
		a[i]=i-read();
		if (a[i]<0) a[i]=n+1;
	}
	for (int i=1;i<=m;i++)
	{
		int l=read()+1,r=n-read();
		q[r].push_back((point){i,l});
	}
	build(1,1,n);
	for (int i=1;i<=n;i++)
	{
		update(1,1,n,i);
		change(1,1,n,a[i]);
		for (point j:q[i])
		{
			ans[j.id]=ask(1,1,n,j.l);
		}
	}
	for (int i=1;i<=m;i++) printf("%d\n",ans[i]);
	return 0;
}