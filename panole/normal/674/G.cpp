#include<bits/stdc++.h>
using namespace std;

int n,q,p,a[150010],ord,x,y,z,len,Cnt,P[10],V[10];
struct node{int l,r,p[5],v[5],cnt,laz;}t[600010],ans;

node merge(node A,node B)
{
	node C;
	C.l=A.l,C.r=B.r,C.cnt=A.cnt,C.laz=0;
	for (int i=0; i<A.cnt; i++) C.p[i]=A.p[i],C.v[i]=A.v[i];
	for (int i=0; i<B.cnt; i++)
	{
		bool bo=0;
		for (int j=0; j<C.cnt; j++)
			if (C.p[j]==B.p[i]) {bo=1,C.v[j]+=B.v[i]; break;}
		if (bo) continue;
		if (C.cnt<len) C.p[C.cnt++]=B.p[i],C.v[C.cnt-1]=B.v[i]; else
		{
			int mi=B.v[i];
			for (int j=0; j<C.cnt; j++) if (C.v[j]<mi) mi=C.v[j];
			Cnt=0;
			for (int j=0; j<C.cnt; j++) if (C.v[j]>mi) P[Cnt++]=C.p[j],V[Cnt-1]=C.v[j]-mi;
			if (B.v[i]>mi) P[Cnt++]=B.p[i],V[Cnt-1]=B.v[i]-mi;
			C.cnt=Cnt;
			for (int j=0; j<Cnt; j++) C.p[j]=P[j],C.v[j]=V[j];
		}
	}
	return C;
}

void build(int i,int l,int r)
{
	if (l==r) 
	{
		t[i].cnt=1,t[i].p[0]=a[l],t[i].v[0]=1; 
		t[i].l=t[i].r=l; return;
	}
	int mid=(l+r)>>1;
	build(i<<1,l,mid),build(i<<1|1,mid+1,r);
	t[i]=merge(t[i<<1],t[i<<1|1]);
}

void pushdown(int i)
{
	if (!t[i].laz) return;
	t[i<<1].laz=t[i].laz,t[i<<1|1].laz=t[i].laz;
	t[i<<1].cnt=1,t[i<<1].p[0]=t[i].laz;
	t[i<<1|1].cnt=1,t[i<<1|1].p[0]=t[i].laz;
	t[i<<1].v[0]=t[i<<1].r-t[i<<1].l+1;
	t[i<<1|1].v[0]=t[i<<1|1].r-t[i<<1|1].l+1;
	t[i].laz=0;
}

void change(int i,int l,int r,int v)
{
	if (t[i].l==l&&t[i].r==r) {t[i].cnt=1,t[i].laz=v,t[i].p[0]=v,t[i].v[0]=r-l+1; return;}
	int mid=(t[i].l+t[i].r)>>1; pushdown(i);
	if (r<=mid) change(i<<1,l,r,v); else 
	if (l>mid) change(i<<1|1,l,r,v); else
	change(i<<1,l,mid,v),change(i<<1|1,mid+1,r,v);
	t[i]=merge(t[i<<1],t[i<<1|1]);
}

node query(int i,int l,int r)
{
	if (t[i].l==l&&t[i].r==r) return t[i];
	int mid=(t[i].l+t[i].r)>>1; pushdown(i);
	if (r<=mid) return query(i<<1,l,r);
	if (l>mid) return query(i<<1|1,l,r);
	return merge(query(i<<1,l,mid),query(i<<1|1,mid+1,r));
}

int main()
{
	scanf("%d%d%d",&n,&q,&p),len=100/p;
	for (int i=1; i<=n; i++) scanf("%d",&a[i]);
	build(1,1,n);
	while (q--)
	{
		scanf("%d",&ord);
		if (ord==1)
		{
			scanf("%d%d%d",&x,&y,&z);
			change(1,x,y,z);
		} else
		{
			scanf("%d%d",&x,&y),ans=query(1,x,y);
			printf("%d ",ans.cnt);
			for (int i=0; i<ans.cnt; i++) printf("%d ",ans.p[i]);
			puts("");
		}
	}
	return 0;
}