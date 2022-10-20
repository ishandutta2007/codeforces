#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1.5e5+5;
const int p=998244353;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int pw[N];
struct trie
{
	int son[N*30][2],sum[N*30],cnt=1;
	void insert(int x)
	{
		sum[1]++;
		int now=1;
		for (int i=29;i>=0;i--)
		{
			if (!son[now][x>>i&1]) son[now][x>>i&1]=++cnt;
			now=son[now][x>>i&1];
			sum[now]++;
		}
	}
	int query(int u,int v,int d,int x)
	{
		if (!u) swap(u,v);
		if (!u) return 1;
		if (!v) return pw[sum[u]];
		if (d<0) return u==v?pw[sum[u]]:pw[sum[u]+sum[v]];
		if (u==v)
		{
			if (x>>d&1) return query(son[u][0],son[u][1],d-1,x);
				   else return (query(son[u][0],son[u][0],d-1,x)+query(son[u][1],son[u][1],d-1,x)-1)%p;
		}
		else
		{
			if (x>>d&1) return 1LL*query(son[u][0],son[v][1],d-1,x)*query(son[u][1],son[v][0],d-1,x)%p;
			else return (query(son[u][0],son[v][0],d-1,x)+query(son[u][1],son[v][1],d-1,x)-1
				+1LL*(pw[sum[son[u][0]]]-1)*(pw[sum[son[u][1]]]-1)
				+1LL*(pw[sum[son[v][0]]]-1)*(pw[sum[son[v][1]]]-1)
			)%p;
		}
	}
}t;

signed main()
{
	int n=read(),x=read();
	for (int i=1;i<=n;i++) t.insert(read());
	for (int i=pw[0]=1;i<=n;i++) pw[i]=2*pw[i-1]%p;
	print((t.query(1,1,29,x)+p-1)%p);
	
	return 0;
}