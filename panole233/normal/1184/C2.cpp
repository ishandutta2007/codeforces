#include<bits/stdc++.h>
using namespace std;

int t[24000010],laz[24000010],ans,n,r,cnt,x,y;
struct lin{int y,xl,xr,val;}a[600010];
bool cmp(const lin&a,const lin&b) {return a.y<b.y;}

void pushdown(int i)
{
	t[i<<1]+=laz[i],t[i<<1|1]+=laz[i];
	laz[i<<1]+=laz[i],laz[i<<1|1]+=laz[i];
	laz[i]=0;
}

void add(int i,int l,int r,int ql,int qr,int v)
{
	if (l==ql&&r==qr) {t[i]+=v,laz[i]+=v; return;}
	pushdown(i); int mid=(l+r)>>1;
	if (qr<=mid) add(i<<1,l,mid,ql,qr,v); else
	if (ql>mid) add(i<<1|1,mid+1,r,ql,qr,v); else
	add(i<<1,l,mid,ql,mid,v),add(i<<1|1,mid+1,r,mid+1,qr,v);
	t[i]=max(t[i<<1],t[i<<1|1]);
}

int main()
{
	scanf("%d%d",&n,&r),cnt=0;
	for (int i=1; i<=n; i++) 
	{
		scanf("%d%d",&x,&y);
		a[++cnt]=(lin){x-y-r,x+y-r,x+y+r,1};
		a[++cnt]=(lin){x-y+r+1,x+y-r,x+y+r,-1};
	}
	sort(a+1,a+1+cnt,cmp),ans=0;
	for (int i=1; i<=cnt; i++)
	{
		int I=i;
		while (I<cnt&&a[I+1].y==a[I].y) I++;
		for (int j=i; j<=I; j++) add(1,-3000000,3000000,a[j].xl,a[j].xr,a[j].val);
		ans=max(ans,t[1]);
		i=I;
	}
	printf("%d\n",ans);
	return 0;
}