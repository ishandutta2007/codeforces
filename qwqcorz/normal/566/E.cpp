#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e3+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

bitset<N>a[N];
bool check(int n)
{
	for (int i=1;i<=n;i++) if ((int)a[i].count()!=n) return 0;
	return 1;
}
vector<pair<int,int>>ans;
bitset<N>is,e[N];
void add_edge(int u,int v,bool flag=1)
{
	if (e[u][v]) return;
	ans.push_back(make_pair(u,v));
	if (!flag) return;
	e[u].set(v),e[v].set(u);
	is.set(u),is.set(v);
}
int id[N];

signed main()
{
	int n=read();
	for (int i=1;i<=n;i++)
	{
		e[i].set(i);
		int m=read();
		for (int j=1;j<=m;j++) a[i].set(read());
	}
	if (n==2) return puts("1 2"),0;
	if (check(n))
	{
		for (int i=2;i<=n;i++) print(1,' '),print(i);
		return 0;
	}
	for (int i=1;i<=n;i++)
	for (int j=i+1;j<=n;j++)
	{
		auto res=a[i]&a[j];
		if ((int)res.count()==2)
		{
			int x=res._Find_first();
			add_edge(x,res._Find_next(x));
		}
	}
	if ((int)is.count()==2)
	{
		int x=is._Find_first(),y=is._Find_next(x),z=0;
		for (int i=1;i<=n;i++) if ((int)a[i].count()!=n){z=i;break;}
		for (int i=1;i<=n;i++)
		if ((int)a[i].count()!=n&&a[i]!=a[z])
		{
			auto A=a[z]^is,B=a[i]^is;
			for (int j=1;j<=n;j++) if (A[j]) add_edge(x,j);
			for (int j=1;j<=n;j++) if (B[j]) add_edge(y,j);
			break;
		}
	}
	else
	{
		static int siz[N];
		for (int i=1;i<=n;i++) siz[i]=a[i].count();
		for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
		if (a[j][i]&&(!id[i]||siz[j]<siz[id[i]])) id[i]=j;
		for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
		if ((a[id[i]]&is)==e[j])
		{
			add_edge(i,j,0);
			break;
		}
	}
	for (auto i:ans) print(i.first,' '),print(i.second);
	
	return 0;
}
/*
5
3 1 2 3
4 1 2 3 4
5 1 2 3 4 5
4 2 3 4 5
3 3 4 5

*/