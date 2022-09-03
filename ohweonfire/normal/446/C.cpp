#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#define upd(x) if((x)>mod)(x)-=mod;
#define abs(x) ((x)<0?-(x):x)
#define Ca(a,b,x) (((a)*fib[abs(x-1)]+(b)*fib[x])%mod)
#define Sum(a,b,x) (((a)*fib[x]+(b)*(fib[(x)+1]-1)+mod)%mod)
using namespace std;
const int maxn=300005;
const int mod=1000000009;
typedef long long LL;
struct node{
	int l,r;
	LL val,a,b;
}seg[maxn*4];
LL arr[maxn],ans,fib[maxn];
int n,m,x,y,op;
LL create(int l,int r,int t)
{
	seg[t].l=l;
	seg[t].r=r;
	seg[t].a=seg[t].b=0;
	if(l==r)
		seg[t].val=arr[l];
	else
	{
		int mid=l+r>>1;
		seg[t].val=create(l,mid,t<<1)+create(mid+1,r,(t<<1)+1);
	}
	upd(seg[t].val);
	return seg[t].val;
}
void add(int l,int r,int t,int a,int b)
{
	seg[t].val+=Sum(a,b,r-l+1);
	upd(seg[t].val);
	if(seg[t].l==l&&seg[t].r==r)
	{
		seg[t].a+=a;
		seg[t].b+=b;
		upd(seg[t].a);
		upd(seg[t].b);
	}
	else
	{
		int mid=seg[t].l+seg[t].r>>1;
		if(r<=mid)
			add(l,r,t<<1,a,b);
		else if(l>mid)
			add(l,r,(t<<1)+1,a,b);
		else
		{
			add(l,mid,t<<1,a,b);
			add(mid+1,r,(t<<1)+1,Ca(a,b,mid-l+1),Ca(a,b,mid-l+2));
		}
	}
}
void Query(int l,int r,int t)
{
	if(seg[t].l==l&&seg[t].r==r)
	{
		ans+=seg[t].val;
		upd(ans);
	}
	else
	{
		ans+=Sum(Ca(seg[t].a,seg[t].b,l-seg[t].l),Ca(seg[t].a,seg[t].b,l-seg[t].l+1),r-l+1);
		upd(ans);
		int mid=seg[t].l+seg[t].r>>1;
		if(r<=mid)
			Query(l,r,t<<1);
		else if(l>mid)
			Query(l,r,(t<<1)+1);
		else
		{
			Query(l,mid,t<<1);
			Query(mid+1,r,(t<<1)+1);
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n+2;i++)
	{
		if(i<3)fib[i]=1;
		else
		{
			fib[i]=fib[i-1]+fib[i-2];
			upd(fib[i]);
		}
		if(i<=n)scanf("%I64d",arr+i);
	}
	create(1,n,1);
	while(m--)
	{
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d%d",&x,&y);
			add(x,y,1,1,1);
		}
		else
		{
			scanf("%d%d",&x,&y);
			ans=0;
			Query(x,y,1);
			printf("%I64d\n",ans);
		}
	}
	return 0;
}