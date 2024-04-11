#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct pt
{
	int l,r;
	pt(int l=0,int r=0):l(l),r(r){}
}a[1000005],b[1000005];
int n,at,bt,t,val=1e9+1;
int sum[10000005][2],ls[10000005],rs[10000005],cnt=1,lazy[10000005][2];
//int sum2[10000005][2];
void pushup(int x)
{
	sum[x][0]=max(sum[ls[x]][0],sum[rs[x]][0]);
	sum[x][1]=max(sum[ls[x]][1],sum[rs[x]][1]);
//	sum2[x][0]=sum2[ls[x]][0]+sum2[rs[x]][0];
//	sum2[x][1]=sum2[ls[x]][1]+sum2[rs[x]][1];
}
void col(int x,int v,int fl)
{
	sum[x][fl]+=v;
	lazy[x][fl]+=v;
}
void pushdown(int x)
{
	if(lazy[x][0])
	{
		if(!ls[x]) ls[x]=++cnt;
		if(!rs[x]) rs[x]=++cnt;
		col(ls[x],lazy[x][0],0);
		col(rs[x],lazy[x][0],0);
		lazy[x][0]=0;
	}
	if(lazy[x][1])
	{
		if(!ls[x]) ls[x]=++cnt;
		if(!rs[x]) rs[x]=++cnt;
		col(ls[x],lazy[x][1],1);
		col(rs[x],lazy[x][1],1);
		lazy[x][1]=0;
	}
}
int modify(int x,int l,int r,int qx,int v,int fl)
{
	if(l>qx||r<qx) return x;
	if(!x)
	{
		x=++cnt;
		sum[x][0]=sum[x][1]=0;
		ls[x]=rs[x]=0;
	}
	//if(x==1) printf("modify:qx=%d,v=%d,fl=%d\n",qx,v,fl);
	if(l==r)
	{
		sum[x][fl]=max(sum[x][fl],v);
		//sum2[x][fl]++;
		return x;
	}
	int mid=(l+r)/2;
	pushdown(x);
	ls[x]=modify(ls[x],l,mid,qx,v,fl);
	rs[x]=modify(rs[x],mid+1,r,qx,v,fl);
	pushup(x);
	return x;
}
int modify2(int x,int l,int r,int ql,int qr,int v,int fl)
{
	if(l>qr||r<ql) return x;
	if(!x)
	{
		x=++cnt;
		sum[x][0]=sum[x][1]=0;
		ls[x]=rs[x]=0;
	}
	//if(x==1) printf("modify2:ql=%d,qr=%d,v=%d,fl=%d\n",ql,qr,v,fl);
	if(ql<=l&&r<=qr)
	{
		col(x,v,fl);
		return x;
	}
	int mid=(l+r)/2;
	pushdown(x);
	ls[x]=modify2(ls[x],l,mid,ql,qr,v,fl);
	rs[x]=modify2(rs[x],mid+1,r,ql,qr,v,fl);
	pushup(x);
	return x;
}
int query(int x,int l,int r,int ql,int qr,int fl)
{
	//if(x==1) printf("modify:ql=%d,qr=%d,fl=%d\n",ql,qr,fl);
	if(l>qr||r<ql||!x) return 0;
	if(ql<=l&&r<=qr) return sum[x][fl];
	pushdown(x);
	int mid=(l+r)/2;
	return max(query(ls[x],l,mid,ql,qr,fl),query(rs[x],mid+1,r,ql,qr,fl));
}
/*int query2(int x,int l,int r,int ql,int qr,int fl)
{
	if(l>qr||r<ql) return 0;
	if(ql<=l&&r<=qr) return sum2[x][fl];
	int mid=(l+r)/2;
	return query(ls[x],l,mid,ql,qr,fl)+query(rs[x],mid+1,r,ql,qr,fl);
}*/
/*void print(int x,int l,int r)
{
	if(!x) return;
	printf("x=%d,l=%d,r=%d,sum=%d,%d\n",x,l,r,sum[x][0],sum[x][1]);
	if(l==r) return;
	int mid=(l+r)/2;
	print(ls[x],l,mid);
	print(rs[x],mid+1,r);
}*/
bool operator<(const pt x,const pt y)
{
	return x.r==y.r?x.l>y.l:x.r<y.r;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int l,r,t;
		scanf("%d%d%d",&l,&r,&t);
		if(t==1)
		{
			a[++at].l=l;
			a[at].r=r;
		}
		else
		{
			b[++bt].l=l;
			b[bt].r=r;
		}
	}
	sort(a+1,a+at+1);
	sort(b+1,b+bt+1);
	/*for(int i=1;i<=n;i++)
	{
		modify(1,1,n,a[i].l,0,0);
		a[i].c=query(1,1,n,a[i].l,a[i].r,0);
	}
	for(int i=1;i<=n;i++)
	{
		modify(1,1,n,b[i].l,0,1);
		b[i].c=query(1,1,n,b[i].l,b[i].r,1);
	}*/
	int nwa=1,nwb=1;
	a[at+1].r=b[bt+1].r=1e9;
	while(nwa<=at||nwb<=bt)
	{
		if(a[nwa].r<b[nwb].r)
		{
			modify2(1,1,val,1,a[nwa].l,1,1);
			int q=query(1,1,val,1,a[nwa].r+1,1);
			//printf("a:l=%d,r=%d,q=%d\n",a[nwa].l,a[nwa].r,q);
			modify(1,1,val,a[nwa].r+1,q,0);
			nwa++;
		}
		else
		{
			modify2(1,1,val,1,b[nwb].l,1,0);
			int q=query(1,1,val,1,b[nwb].r+1,0);
			//printf("b:l=%d,r=%d,q=%d\n",b[nwb].l,b[nwb].r,q);
			modify(1,1,val,b[nwb].r+1,q,1);
			nwb++;
		}
	//	printf("nwa=%d,nwb=%d\n",nwa,nwb);
	}
//	printf("ls=%d,rs=%d\n",ls[1],rs[1]);
	printf("%d\n",max(sum[1][0],sum[1][1]));
	return 0;
}