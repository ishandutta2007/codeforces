#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LC k<<1
#define RC k<<1|1

typedef long long LL;

const int N=3100000;
const int M=11100000;
const LL mod=1e9+7;
int n,q,k;
struct query
{
	int op,x,y,z,t;
}a[N];
int r[N];
int last[N],e[M],pre[M],num;
void add(int k,int l,int r,int a,int b,int id)
{
	if (l==a&&r==b)
	{
		e[++num]=id,pre[num]=last[k],last[k]=num;
		return;
	}
	int mid=(l+r)/2;
	if (b<=mid) add(LC,l,mid,a,b,id);
	else if (a>mid) add(RC,mid+1,r,a,b,id);
	else add(LC,l,mid,a,mid,id),add(RC,mid+1,r,mid+1,b,id);
}
int fa[N],sz[N],st[N],sf[N],sp[N],sp2[N],top;
int find(int x)
{
	if (fa[x]==x) return x;
	return find(fa[x]);
}
void Union(int x,int y)
{
	if (!x||!y||x==y) return;
	x=find(x),y=find(y);
	if (x==y) return;
	if (sz[x]>sz[y]) swap(x,y);
	st[++top]=x;
	sf[top]=x;
	sp[top]=y,sp2[top]=sz[y];
	fa[x]=y;
	sz[y]=sz[x]+sz[y];
}
void clear(int base)
{
	for (;top>base;top--)
	{
		fa[st[top]]=sf[top];
		sz[sp[top]]=sp2[top];
	}
}
void work(int k,int l,int r)
{
	int base=top;
	for (int i=last[k];i;i=pre[i])
	{
		int x=a[e[i]].x,y=a[e[i]].y;
		Union(x,y);
	}
	if (l==r)
	{
		if (a[l].op==2)
		{
			int fx=find(a[l].z);
			printf("%d\n",sz[fx]);
		}
		clear(base);
		return;
	}
	int mid=(l+r)/2;
	work(LC,l,mid);
	work(RC,mid+1,r);
	clear(base);
}
int main()
{
	scanf("%d %d %d",&n,&q,&k);
	for (int i=1;i<=q+k;i++)
		r[i]=q;
	int cnt=1;
	for (int i=1;i<=q;i++)
	{
		int x,y,z;
		scanf("%d",&a[i].op);
		if (a[i].op==1) scanf("%d %d",&a[i].x,&a[i].y),a[i].t=cnt;
		else if (a[i].op==2) scanf("%d",&a[i].z);
		else
		{
			r[cnt]=i;
			cnt++;
		}
	}
	for (int i=1;i<=q;i++)
	{
		if (a[i].op==1)
		{
			int x=a[i].x,y=a[i].y,t=a[i].t+k-1;
			add(1,1,q,i,r[t],i);
		}
	}
	for (int i=1;i<=n;i++)
		fa[i]=i,sz[i]=1;
	work(1,1,q);
	return 0;
}