#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<set>
#include<map>
#include<iostream>

#define fi first
#define se second
#define mk make_pair
#define pb push_back

#define ls (t<<1)
#define rs ((t<<1)|1)
#define mid ((l+r)>>1)

#define N 200005

using namespace std;

long long Sum[N*4];

int add[N*4],Min[N*4],a[N],n,m,i;

void down(int t,int len)
{
	if (!add[t]) return;
	add[ls]=add[rs]=add[t];
	Sum[ls]=1ll*add[t]*((len+1)>>1);
	Sum[rs]=1ll*add[t]*(len>>1);
	Min[ls]=Min[rs]=add[t];
	add[t]=0;
}

void build(int l,int r,int t)
{
	if (l==r) Min[t]=Sum[t]=a[l];
	else
	{
		build(l,mid,ls); build(mid+1,r,rs);
		Sum[t]=Sum[ls]+Sum[rs];
		Min[t]=Min[rs];
	}
}

int FindLe(long long c,int l,int r,int t)
{
	if (l==r) return l;
	else
	{
		down(t,r-l+1);
		if (Min[ls]<=c) return FindLe(c,l,mid,ls);
		return FindLe(c,mid+1,r,rs);
	}
}

void Modify(int ll,int rr,int c,int l,int r,int  t)
{
	if (ll<=l&&r<=rr) 
	{
		Sum[t]=1ll*c*(r-l+1);
		add[t]=c;
		Min[t]=c;
	}
	else
	{
		down(t,r-l+1);
		if (ll<=mid) Modify(ll,rr,c,l,mid,ls);
		if (rr>mid)  Modify(ll,rr,c,mid+1,r,rs);
		Sum[t]=Sum[ls]+Sum[rs];
		Min[t]=Min[rs];
	}
}

long long GetSum(int ll,int l,int r,int t)
{
	if (l==r) return Sum[t];
	else
	{
		down(t,r-l+1);
		if (ll<=mid) return GetSum(ll,l,mid,ls);
		else return Sum[ls]+GetSum(ll,mid+1,r,rs);
	}
}

int FindSumLe(long long c,int l,int r,int t)
{
	if (l==r) return (c<Sum[t]?-1:l);
	else
	{
		down(t,r-l+1);
		if (Sum[ls]>c) return FindSumLe(c,l,mid,ls);
		else return max(mid,FindSumLe(c-Sum[ls],mid+1,r,rs));
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;++i) scanf("%d",&a[i]);
	build(1,n+1,1);
	for (;m--;)
	{
		int ty,x; long long y;
		scanf("%d%d%I64d",&ty,&x,&y); 
		if (ty==1)
		{
			int w=FindLe(y,1,n+1,1);
			if (w<=x) Modify(w,x,y,1,n+1,1);
		}
		else
		{
			int nowpos=x,Counter=0;
			for (;nowpos!=n+2;)
			{
				int w=FindLe(y,1,n+1,1);
				w=max(w,nowpos);
				long long s;
				if (w==1) s=0; else s=GetSum(w-1,1,n+1,1);
				nowpos=FindSumLe(s+y,1,n+1,1);
				y-=GetSum(nowpos,1,n+1,1)-s; Counter+=nowpos-w+1;
				nowpos++;
			}
			printf("%d\n",Counter-1); 
		}
	}
}