// This amazing code is by Eric Sunli Chen.
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;
template<typename T> bool get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'&&t!=EOF; t=getchar());
	if(t=='-')neg=true,t=getchar();if(t==EOF)return false;
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;return true;
}
template<typename T> void print_int(T x)
{
	if(x<0)putchar('-'),x=-x;
	short a[20]= {},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1; i>=0; i--)putchar('0'+a[i]);
}
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define get1(a) get_int(a)
#define get2(a,b) (get1(a)&&get1(b))
#define get3(a,b,c) (get1(a)&&get2(b,c))
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

inline LL dv(const LL&a,const LL&b){return a/b-((a^b)<0&&a%b);}
bool Qtp;
int insert_tot;
struct line
{
	LL k,b;
	mutable LL pos;
	line(LL _k,LL _b,LL _pos):k(_k),b(_b),pos(_pos){}
	bool operator<(const line&a)const
	{
		if(Qtp)return pos<a.pos;
		else return k<a.k;
	}
};
typedef multiset<line>::iterator itr;
struct cvh
{
	multiset<line>a;
//	cvh(){a.insert(line(0,0,Linf));}
	bool inter(itr x,itr y)
	{
		if(y==a.end())
		{
			x->pos=Linf;
			return false;
		}
		if(x->k==y->k)
		{
			if(x->b > y->b)x->pos=Linf;
			else x->pos=-Linf;
		}
		else x->pos=dv(y->b-x->b,x->k-y->k);
		return x->pos>=y->pos;
	}
	void insert(LL k,LL b)
	{
		insert_tot++;
		if(insert_tot%1000000==0)printf("insert times= %d\n",insert_tot);
		itr z=a.insert(line(k,b,0)),y=z++,x=y;
		while(inter(y,z))z=a.erase(z);
		if(x!=a.begin()&&inter(--x,y))inter(x,y=a.erase(y));
		while((y=x)!=a.begin()&&(--x)->pos>=y->pos)
			inter(x,a.erase(y));
	}
	LL query(int x)
	{
		Qtp=1;itr ret=a.lower_bound(line(0,0,x));Qtp=0;
		return ret->k*x+ret->b;
	}
	void debug()
	{
		for(auto&v:a)
		{
			printf("%I64d * x + %I64d ",v.k,v.b);
			if(v.pos==Linf)printf("range= inf\n");
			else printf("range= %I64d\n",v.pos);
		}
	}
};

cvh st[100111];
vector<int>g[100111];
int n,a[100111],b[100111],sz[100111],son[100111];
void dfs(int x,int f=0)
{
	sz[x]=1;
	for(auto&v:g[x])if(v!=f)
	{
		dfs(v,x);
		sz[x]+=sz[v];
		if(sz[son[x]]<sz[v])son[x]=v;
	}
}
LL dp[100111];
void dfs2(int x,int f=0)
{
//	printf("dfs2= %d f=%d\n",x,f);
	if(son[x])
	{
		dfs2(son[x],x);
		swap(st[son[x]].a,st[x].a);
		for(auto&v:g[x])if(v!=f&&v!=son[x])
		{
			dfs2(v,x);
			for(auto cur:st[v].a)
				st[x].insert(cur.k,cur.b);
			st[v].a.clear();
		}
		dp[x]=-st[x].query(a[x]);
	}
	st[x].insert(-b[x],-dp[x]);
}
int main()
{
	get1(n);
	for(int i=1;i<=n;i++)get1(a[i]);
	for(int i=1;i<=n;i++)get1(b[i]);
	for(int i=1,u,v;i<n;i++)
	{
		get2(u,v);
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(1);
	dfs2(1);
	for(int i=1;i<=n;i++)printf("%I64d ",dp[i]);
	return 0;
}