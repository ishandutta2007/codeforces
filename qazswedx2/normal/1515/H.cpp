#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,val=(1<<20),sum[10000005][2],ch[10000005][2],lazy[10000005],sz[10000005],rt;
int ct;
void pushup(int x)
{
	sum[x][0]=sum[ch[x][0]][0]|sum[ch[x][1]][0];
	sum[x][1]=sum[ch[x][0]][1]|sum[ch[x][1]][1];
	sz[x]=sz[ch[x][0]]+sz[ch[x][1]];
}
void col(int x,int l,int r,int v)
{
	lazy[x]^=v;
	int v0=sum[x][0]&v,v1=sum[x][1]&v;
	sum[x][0]+=v1-v0;
	sum[x][1]+=v0-v1;
	if(((r-l+1)>>1)&v) swap(ch[x][0],ch[x][1]);
}
void pushdown(int x,int l,int r)
{
	if(lazy[x])
	{
		int mid=(l+r)/2;
		if(ch[x][0]) col(ch[x][0],l,mid,lazy[x]);
		if(ch[x][1]) col(ch[x][1],mid+1,r,lazy[x]);
		lazy[x]=0;
	}
}
int modify(int x,int l,int r,int qx)
{
	if(l>qx||r<qx) return x;
	if(!x) x=++ct;
	if(l==r)
	{
		sz[x]=1;
		sum[x][1]=l;
		sum[x][0]=(val-1)-l;
		return x;
	}
	pushdown(x,l,r);
	int mid=(l+r)/2;
	ch[x][0]=modify(ch[x][0],l,mid,qx);
	ch[x][1]=modify(ch[x][1],mid+1,r,qx);
	pushup(x);
	return x;
}
void split(int x,int l,int r,int &L,int &R,int k)
{
	if(!x) 
	{
		L=R=0;
		return;
	}
	if(l==r)
	{
		if(l<=k)
			L=x;
		else R=x;
		return;
	}
	pushdown(x,l,r);
	int mid=(l+r)/2;
	L=++ct;
	R=++ct;
	if(k<mid)
	{
		ch[R][1]=ch[x][1];
		split(ch[x][0],l,mid,ch[L][0],ch[R][0],k);
	}
	else
	{
		ch[L][0]=ch[x][0];
		split(ch[x][1],mid+1,r,ch[L][1],ch[R][1],k);
	}
	pushup(L);
	pushup(R);
}
int merge(int x,int y,int l,int r,int k)
{
	if(!x||!y)
	{
		if(x) col(x,l,r,k);
		return x+y;
	}
	if(l==r) return y;
	int mid=(l+r)/2;
	pushdown(x,l,r);
	pushdown(y,l,r);
	ch[x][0]=merge(ch[x][0],ch[y][0],l,mid,k);
	ch[x][1]=merge(ch[x][1],ch[y][1],mid+1,r,k);
	pushup(x);
	return x;
}
void modifyor(int x,int l,int r,int k)
{
	if((sum[x][0]&sum[x][1]&k)==0)
	{
		col(x,l,r,sum[x][0]&k);
		return;
	}
	if(l==r) return;
	pushdown(x,l,r);
	int nw=(sum[x][0]&sum[x][1]&k);
	int mid=(l+r)/2;
//	printf("modifyor:x=%d,l=%d,r=%d,k=%d,nw=%d,sz=%d\n",x,l,r,k,nw,sz[x]);
	if(k&((r-l+1)>>1))
	{
		ch[x][1]=merge(ch[x][0],ch[x][1],l,mid,(r-l+1)>>1);
		ch[x][0]=0;
	}
	modifyor(ch[x][0],l,mid,k);
	modifyor(ch[x][1],mid+1,r,k);
	pushup(x);
}
void print(int x,int l,int r)
{
	if(!x) return;
	printf("x=%d,l=%d,r=%d,sum=%d,%d,sz=%d\n",x,l,r,sum[x][0],sum[x][1],sz[x]);
	if(l==r) return;
	pushdown(x,l,r);
	int mid=(l+r)/2;
	print(ch[x][0],l,mid);
	print(ch[x][1],mid+1,r);
}
int main()
{
//	freopen("CF1515H.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		rt=modify(rt,0,val-1,x);
	}
//	print(rt,0,val-1);
	for(int i=1;i<=m;i++)
	{
		int op,l,r,x;
		scanf("%d%d%d",&op,&l,&r);
		int u,v,w;
		split(rt,0,val-1,u,v,r);
		split(u,0,val-1,w,rt,l-1);
	//	print(v,0,val-1);
	//	print(w,0,val-1);
	//	printf("qwq\n");
	//	print(rt,0,val-1);
		if(op==1)
		{
			scanf("%d",&x);
			col(rt,0,val-1,val-1);
		//	printf("qaaq\n");
		//	print(rt,0,val-1);
			modifyor(rt,0,val-1,val-1-x);
		//	printf("qaq\n");
		//	print(rt,0,val-1);
			col(rt,0,val-1,val-1);
		}
		if(op==2)
		{
			scanf("%d",&x);
			modifyor(rt,0,val-1,x);
		}
		if(op==3)
		{
			scanf("%d",&x);
			col(rt,0,val-1,x);
		}
		if(op==4)
			printf("%d\n",sz[rt]);
		rt=merge(merge(w,rt,0,val-1,0),v,0,val-1,0);
		//printf("qwwq\n");
		//print(rt,0,val-1);
	}
	return 0;
}