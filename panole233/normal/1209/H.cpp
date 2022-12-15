#include<bits/stdc++.h>
using namespace std;

int n,L,id[400010];
double f[400010];
struct node{int l,r; double v;}a[200010];
struct seg{int l,r; double laz,mi;}t[1600010];

void build(int i,int l,int r)
{
	t[i].l=l,t[i].r=r;
	if (l==r) {t[i].mi=f[l]; return;}
	int mid=(l+r)>>1;
	build(i<<1,l,mid),build(i<<1|1,mid+1,r);
	t[i].mi=min(t[i<<1].mi,t[i<<1|1].mi);
}

bool cmp(const int &x,const int &y) {return a[x].v<a[y].v;}

void pushdown(int i)
{
	t[i<<1].mi+=t[i].laz,t[i<<1].laz+=t[i].laz;
	t[i<<1|1].mi+=t[i].laz,t[i<<1|1].laz+=t[i].laz;
	t[i].laz=0;
}

void mns(int i,int l,int r,double v)
{
	if (t[i].l==l&&t[i].r==r) {t[i].laz-=v,t[i].mi-=v; return;}
	pushdown(i); int mid=(t[i].l+t[i].r)>>1;
	if (r<=mid) mns(i<<1,l,r,v); else
	if (l>mid) mns(i<<1|1,l,r,v); else
	mns(i<<1,l,mid,v),mns(i<<1|1,mid+1,r,v);
	t[i].mi=min(t[i<<1].mi,t[i<<1|1].mi);
}

double query(int i,int l,int r)
{
	if (t[i].l==l&&t[i].r==r) return t[i].mi;
	pushdown(i); int mid=(t[i].l+t[i].r)>>1;
	if (r<=mid) return query(i<<1,l,r);
	if (l>mid) return query(i<<1|1,l,r);
	return min(query(i<<1,l,mid),query(i<<1|1,mid+1,r));
}

int main()
{
	scanf("%d%d",&n,&L);
	for (int i=1; i<=n; i++) scanf("%d%d%lf",&a[i].l,&a[i].r,&a[i].v);
	f[0]=0,a[0].r=0;
	for (int i=1; i<=n; i++) 
	{
		f[2*i-1]=max(f[2*i-2]-0.5*(a[i].l-a[i-1].r),0.0);
		f[2*i]=f[2*i-1]+(1.0/a[i].v)*(a[i].r-a[i].l);
	}
	f[2*n+1]=max(f[2*n]-0.5*(L-a[n].r),0.0);
	if (f[2*n+1]>1e-10)
	{
		build(1,0,2*n+1);
		for (int i=1; i<=n; i++) id[i]=i;
		sort(id+1,id+1+n,cmp);
		for (int i=1; i<=n; i++)
		{
			double nw=query(1,id[i]*2,2*n+1),la=query(1,id[i]*2-1,id[i]*2-1);
			double lim=(a[id[i]].r-a[id[i]].l)/(a[id[i]].v+2)+(a[id[i]].r-a[id[i]].l)/a[id[i]].v;
			if (nw<lim) mns(1,id[i]*2,2*n+1,nw); else mns(1,id[i]*2,2*n+1,lim);
		}
		for (int i=1; i<=2*n+1; i++) f[i]=query(1,i,i);
	}
	double ans=0,v;
	for (int i=1; i<=n; i++)
	{
		if (a[i].l!=a[i-1].r)
		{
			v=1.0/(1-(f[2*i-2]-f[2*i-1])/(a[i].l-a[i-1].r));
			ans+=(a[i].l-a[i-1].r)/v;
		}
		if (a[i].r!=a[i].l)
		{
			v=(a[i].v+1)/(1-(f[2*i-1]-f[2*i])/(a[i].r-a[i].l));
			ans+=(a[i].r-a[i].l)/v;
		}
	}
	if (a[n].r!=L)
	{
		v=1.0/(1-(f[2*n]-f[2*n+1])/(L-a[n].r));
		ans+=(L-a[n].r)/v;
	}
	printf("%.10lf\n",ans);
	return 0;
}