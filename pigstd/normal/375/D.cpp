#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M=1e5+10;
const int N=sqrt(M)+10;
int n,q,dfn[M],size[M],p[M],aa[M],a[M],ans[M],bl;

int id(int k){return (k-1)/bl+1;}

struct edge
{
	int to,next;
}e[M<<1];int head[M],cnt,ti;
void adde(int u,int to)
{
	e[++cnt].to=to,e[cnt].next=head[u],head[u]=cnt;
}

void dfs(int u,int fa)
{
	dfn[u]=++ti,size[u]=1,aa[ti]=a[u];
	for (int i=head[u];i;i=e[i].next)
		if (e[i].to!=fa)
			dfs(e[i].to,u),size[u]+=size[e[i].to];
}

struct query
{
	int l,r,k,id;
}Q[M];

bool cmp(query a,query b)
{
	return id(a.l)<id(b.l)||(id(a.l)==id(b.l)&&id(a.r)<id(b.r));
} 

struct miaomiaomiao
{
	int a[M],sum[N];
	void update(int k,int z)
	{
		sum[id(k)]+=z,a[k]+=z;
	}
	int ask(int k)
	{
		int r=0;
		for (int i=1;i<id(k);i++)r+=sum[i];
		for (int i=bl*(id(k)-1)+1;i<=k;i++)r+=a[i];
		return r;
	}
	int query(int l,int r)
	{
		return ask(r)-ask(l-1);
	}
}T;
// O(1)  O(sqrt(n))  

void add(int k)
{
	T.update(p[k]+1,-1);
	p[k]++;
	T.update(p[k]+1,1);
}

void del(int k)
{
	T.update(p[k]+1,-1);
	p[k]--;
	T.update(p[k]+1,1);
}

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

signed main()
{
	n=read(),q=read();
	bl=sqrt(n);
	for (int i=1;i<=n;i++)a[i]=read(); 
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		adde(u,v),adde(v,u);
	}
	dfs(1,0);
	for (int i=1;i<=q;i++)
	{
		int u=read();Q[i].k=read();
		Q[i].id=i,Q[i].l=dfn[u],Q[i].r=dfn[u]+size[u]-1;
	}
	sort(Q+1,Q+1+q,cmp);int l=1,r=0;
	for (int i=1;i<=q;i++)
	{
		while(r<Q[i].r)add(aa[++r]);
		while(l>Q[i].l)add(aa[--l]);
		while(r>Q[i].r)del(aa[r--]);
		while(l<Q[i].l)del(aa[l++]);
		ans[Q[i].id]=T.query(Q[i].k+1,n+1);
	}
	for (int i=1;i<=q;i++)cout<<ans[i]<<endl;
	return 0;
}
/*
8 1
1 2 2 3 3 2 3 3
1 2
1 5
2 3
2 4
5 6
5 7
5 8
5 3
*/