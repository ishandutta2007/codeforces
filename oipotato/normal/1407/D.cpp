#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<queue>
#include<vector>
#include<map>
#include<cmath>
#include<set>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
const int N=300010;
const int inf=2*N;
int h[N],n;
struct ST_label
{
	int st[20][N],LG,C,lg[N];
	void init(int h[N],int c)
	{
		C=c;
		rep(i,n)st[0][i]=h[i]*C;
		LG=0;
		for(;(1<<LG)<=n;LG++)lg[1<<LG]=LG;
		LG--;
		rep(i,n)lg[i]=max(lg[i],lg[i-1]);
		rep(i,LG)
		for(int j=1;j<=n-(1<<i)+1;j++)
		st[i][j]=min(st[i-1][j],st[i-1][j+(1<<(i-1))]);
	}
	int getmin(int l,int r)
	{
		int len=lg[r-l+1];
		return min(st[len][l],st[len][r-(1<<len)+1]);
	}
	int get(int id,int h)
	{
		h*=C;
		int l=0,r=n-id;
		for(;l<r-1;)
		{
			int mid=(l+r)>>1;
			if(getmin(id+1,id+mid)>h)l=mid;else r=mid;
		}
		return id+l;
	}
}ST[2];
struct Que
{
	int q[N],id[N],top,C;
	int tree[N<<2];
	void build(int p,int le,int ri)
	{
		tree[p]=inf;
		if(le==ri)return;
		int mid=(le+ri)>>1;
		build(p<<1,le,mid);
		build(p<<1|1,mid+1,ri);
	}
	void modify(int p,int le,int ri,int x,int y)
	{
		if(le==ri){tree[p]=y;return;}
		int mid=(le+ri)>>1;
		if(x<=mid)modify(p<<1,le,mid,x,y);
		else modify(p<<1|1,mid+1,ri,x,y);
		tree[p]=min(tree[p<<1],tree[p<<1|1]);
	}
	int get(int p,int le,int ri,int x)
	{
		if(le==ri)return tree[p];
		int mid=(le+ri)>>1;
		if(x<=mid)return min(tree[p<<1|1],get(p<<1,le,mid,x));
		else return get(p<<1|1,mid+1,ri,x);
	}
	void init(int c){top=0;C=c;build(1,1,n);}
	void add(int h,int _id,int ans)
	{
		h*=C;
		for(;top&&h<=q[top];modify(1,1,n,top,inf),top--);
		q[++top]=h;id[top]=_id;modify(1,1,n,top,ans);
	}
	int get(int last)
	{
		int l=0,r=top+1;
		for(;l<r-1;)
		{
			int mid=(l+r)>>1;
			if(id[mid]<=last)r=mid;else l=mid;
		}
		return get(1,1,n,r);
	}
}Q[2];
int main()
{
	scanf("%d",&n);
	rep(i,n)scanf("%d",&h[i]);
	ST[0].init(h,1);
	ST[1].init(h,-1);
	Q[0].init(1);
	Q[1].init(-1);
	Q[0].add(h[n],n,0);Q[1].add(h[n],n,0);
	for(int i=n-1;i;i--)
	{
		int ans=Q[h[i+1]<h[i]].get(ST[h[i+1]<h[i]].get(i,h[i])+1)+1;
		if(i==1){printf("%d\n",ans);break;}
		Q[0].add(h[i],i,ans);Q[1].add(h[i],i,ans);
	}
	return 0;
}