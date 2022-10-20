#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e3+5;
const int M=1e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

struct Query
{
	int opt,x,y,d,l;
}q[M];
int ans[M];
struct bit
{
	int t[N*2],n;
	void send(int _n){n=_n,memset(t,0,sizeof(t));}
	void Add(int x,int y){for (;x<=n;x+=x&-x) t[x]+=y;}
	void add(int l,int r){Add(l,1),Add(r+1,-1);}
	int query(int x){int ret=0;for (;x;x&=x-1) ret+=t[x];return ret;}
}t;
struct bit2
{
	int t[N][N*2],n,m;
	void send(int _n,int _m){n=_n,m=_m,memset(t,0,sizeof(t));}
	void Add(int x,int y,int z)
	{
		for (int i=x;i;i&=i-1)
		for (int j=y;j<=m;j+=j&-j) t[i][j]+=z;
	}
	void add(int x,int l,int r){Add(x,l,1),Add(x,r+1,-1);}
	int query(int x,int y)
	{
		int ret=0;
		for (int i=x;i<=n;i+=i&-i)
		for (int j=y;j;j&=j-1) ret+=t[i][j];
		return ret;
	}
}tx,ty;
void solve(int n,int Q,int o)
{
	t.send(n*2),tx.send(n,n*2),ty.send(n,n*2);
	for (int i=1;i<=Q;i++)
	if (q[i].opt==2)
		ans[i]+=t.query(q[i].x+q[i].y)-
		tx.query(q[i].x,q[i].x+q[i].y)-
		ty.query(q[i].y,q[i].x+q[i].y);
	else if (q[i].d==o)
		t.add(q[i].x+q[i].y,q[i].x+q[i].y+q[i].l),
		tx.add(q[i].x-1,q[i].x+q[i].y,q[i].x+q[i].y+q[i].l),
		ty.add(q[i].y-1,q[i].x+q[i].y,q[i].x+q[i].y+q[i].l);
}

signed main()
{
	int n=read(),Q=read();
	for (int i=1;i<=Q;i++)
	{
		q[i].opt=read();
		if (q[i].opt==1) q[i].d=read(),q[i].x=read(),q[i].y=read(),q[i].l=read();
					else q[i].x=read(),q[i].y=read();
	}
	solve(n,Q,1); for (int i=1;i<=Q;i++) q[i].y=n-q[i].y+1;
	solve(n,Q,2); for (int i=1;i<=Q;i++) q[i].x=n-q[i].x+1;
	solve(n,Q,4); for (int i=1;i<=Q;i++) q[i].y=n-q[i].y+1;
	solve(n,Q,3); for (int i=1;i<=Q;i++) q[i].x=n-q[i].x+1;
	for (int i=1;i<=Q;i++) if (q[i].opt==2) print(ans[i]);
	
	return 0;
}