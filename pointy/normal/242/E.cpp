#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=100005;
int a[N];
struct ST
{
	int l,r,add;
	ll sum;
	#define l(x,y) tree[x][y].l
	#define r(x,y) tree[x][y].r
	#define sum(x,y) tree[x][y].sum
	#define add(x,y) tree[x][y].add
}tree[4*N][22];
int n,m;
void build(int u,int l,int r,int k)
{
	if (l==r) 
	{
		l(u,k)=l,r(u,k)=r,sum(u,k)=!(!(a[l]&(1<<k))),add(u,k)=0;
		return;
	}
	int mid=(l+r)/2;
	l(u,k)=l,r(u,k)=r;
	add(u,k)=0;
	build(u*2,l,mid,k);
	build(u*2+1,mid+1,r,k);
	sum(u,k)=sum(u*2,k)+sum(u*2+1,k);
}
void spread(int u,int k)
{
	if (add(u,k)!=0)
	{
		sum(u*2,k)=(r(u*2,k)-l(u*2,k)+1)-sum(u*2,k);
		sum(u*2+1,k)=(r(u*2+1,k)-l(u*2+1,k)+1)-sum(u*2+1,k);
		add(u*2,k)^=1;
		add(u*2+1,k)^=1;
		add(u,k)=0;
	}
}
void change(int u,int l,int r,int k)
{
	if (l>r) return;
	if (l(u,k)>=l&&r(u,k)<=r)
	{
		add(u,k)^=1;
		sum(u,k)=(r(u,k)-l(u,k)+1)-sum(u,k);
		return;
	}
	spread(u,k);
	int mid=(l(u,k)+r(u,k))/2;
	if (l<=mid) change(u*2,l,r,k);
	if (mid<r) change(u*2+1,l,r,k);
	sum(u,k)=sum(u*2,k)+sum(u*2+1,k);
}
ll ask(int u,int l,int r,int k)
{
	if (l(u,k)>=l&&r(u,k)<=r) return sum(u,k);
	spread(u,k);
	int mid=(l(u,k)+r(u,k))/2;
	ll res=0;
	if (l<=mid) res+=ask(u*2,l,r,k);
	if (mid<r) res+=ask(u*2+1,l,r,k);
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
int main()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=0;i<=20;i++) build(1,1,n,i);
	m=read();
	for (int i=1;i<=m;i++)
	{
		int tp=read();
		if (tp==1)
		{
			int l=read(),r=read();
			ll sum=0,base=1;
			for (int j=0;j<=20;j++)
			{
				sum+=base*ask(1,l,r,j);
				base*=2ll;
			}
			printf("%lld\n",sum);
		}
		else 
		{
			int l=read(),r=read(),x=read();
			for (int j=0;j<=20;j++)
			{
				if ((x&(1ll<<j))>0) change(1,l,r,j);
			}
		}
	}
	return 0;
}