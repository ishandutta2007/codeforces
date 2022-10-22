#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=300005;
struct ST
{
	int l,r;
	ll sum,add;
	#define l(x) tree[x].l
	#define r(x) tree[x].r
	#define sum(x) tree[x].sum
	#define add(x) tree[x].add
}tree[4*N];
int n,m;
void build(int u,int l,int r)
{
	if (l==r) 
	{
		l(u)=l,r(u)=r,sum(u)=0,add(u)=-1;
		return;
	}
	int mid=(l+r)/2;
	l(u)=l,r(u)=r;
	add(u)=-1;
	build(u*2,l,mid);
	build(u*2+1,mid+1,r);
	sum(u)=sum(u*2)+sum(u*2+1);
}
void spread(int u)
{
	if (add(u)!=-1)
	{
		sum(u*2)=add(u)*(r(u*2)-l(u*2)+1);
		sum(u*2+1)=add(u)*(r(u*2+1)-l(u*2+1)+1);
		add(u*2)=add(u);
		add(u*2+1)=add(u);
		add(u)=-1;
	}
}
void change(int u,int l,int r,int k)
{
	if (l>r) return;
	if (l(u)>=l&&r(u)<=r)
	{
		add(u)=k;
		sum(u)=(r(u)-l(u)+1)*k;
		return;
	}
	spread(u);
	int mid=(l(u)+r(u))/2;
	if (l<=mid) change(u*2,l,r,k);
	if (mid<r) change(u*2+1,l,r,k);
	sum(u)=sum(u*2)+sum(u*2+1);
}
ll ask(int u,int l,int r)
{
	if (l(u)>=l&&r(u)<=r)
	{
		return sum(u);
	}
	spread(u);
	int mid=(l(u)+r(u))/2;
	ll res=0;
	if (l<=mid) res+=ask(u*2,l,r);
	if (mid<r) res+=ask(u*2+1,l,r);
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
struct question
{
	int l,r,x;
}q[N];;
int main()
{
	n=read(),m=read();
	for (int i=1;i<=m;i++)
	{
		q[i].l=read(),q[i].r=read(),q[i].x=read();
	}
	build(1,1,n);
	for (int i=m;i>=1;i--)
	{
		change(1,q[i].l,q[i].x-1,q[i].x);
		change(1,q[i].x+1,q[i].r,q[i].x);
	}
	for (int i=1;i<=n;i++) printf("%d ",ask(1,i,i));
	return 0;
}