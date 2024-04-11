// This amazing code is by Eric Sunli Chen.
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;
template<typename T> void get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'; t=getchar());
	if(t=='-')neg=true,t=getchar();
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;
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
#define get2(a,b) get1(a),get1(b)
#define get3(a,b,c) get1(a),get2(b,c)
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

const int maxn=100111;
const int maxp=700111;
struct qtype
{
	int head[maxn],nxt[maxp*20],tot;
	LL bit[maxp*20];
	int v[maxp*20],sz[maxn];
	void clear()
	{
		memset(head,0,sizeof(head));
		tot=0;
	}
	qtype(){clear();}
	void addp(int x,int p)
	{
		for(;x<maxn;x+=x&-x)
		{
			nxt[++tot]=head[x];head[x]=tot;
			bit[tot]=p;sz[x]++;
		}
	}
	void prework()
	{
		tot=0;
		for(int i=0;i<maxn;i++)
		{
			for(int j=head[i];j;j=nxt[j])
				v[++tot]=bit[j];
			head[i]=tot-sz[i]+1;
			sort(v+head[i],v+head[i]+sz[i]);
		}
		for(int i=1;i<=tot;i++)bit[i]=0;
	}
	void add(int x,int p,int vv)
	{
		for(;x<maxn;x+=x&-x)
		{
			int pos=lower_bound(v+head[x],v+head[x]+sz[x],p)-v-head[x]+1;
			for(;pos<=sz[x];pos+=pos&-pos)
				bit[pos+head[x]-1]+=vv;
		}
	}
	LL query(int x,int p)
	{
		LL ret=0;
		for(;x;x-=x&-x)
		{
			int pos=upper_bound(v+head[x],v+head[x]+sz[x],p)-v-head[x];
			for(;pos;pos-=pos&-pos)
				ret+=bit[pos+head[x]-1];
		}
		return ret;
	}
};
qtype sum;

int n,m,a[100111],tp[100111],x[100111],y[100111];
LL ans[100111];
set<int> al[100111];

vector<pair<pii,int> > cmd;
#define addq(x,y,z) cmd.pb(mp(mp(x,y),(z)*v))
void addpoint(int p,int v)
{
	if(p==0||p==n+1)return;
	set<int>::iterator it=al[a[p]].lower_bound(p);it--;
	addq(*it,p,p-*it);
}
void solve()
{
	for(int i=1;i<=n;i++)
	{
		al[i].insert(0);
		al[i].insert(n+1);
		al[a[i]].insert(i);
	}
	set<int>::iterator it;
	for(int i=1;i<=n;i++)addpoint(i,1);
	for(int i=1;i<=m;i++)
	{
		if(tp[i]==2)
		{
			cmd.pb(mp(mp(-x[i],y[i]),i));
			continue;
		}
		int nxt,&p=x[i],&v=y[i];
		
		nxt=*al[a[p]].upper_bound(p);
		addpoint(p,-1);addpoint(nxt,-1);
		al[a[p]].erase(p);
		addpoint(nxt,1);
		
		a[p]=v;
		nxt=*al[a[p]].upper_bound(p);
		addpoint(nxt,-1);
		al[a[p]].insert(p);
		addpoint(p,1);addpoint(nxt,1);
	}
	for(int i=0;i<(int)cmd.size();i++)if(cmd[i].ff.ff>0)sum.addp(cmd[i].ff.ff,cmd[i].ff.ss);
	
	sum.prework();
	for(int i=0;i<(int)cmd.size();i++)
	{
		if(cmd[i].ff.ff>0)
			sum.add(cmd[i].ff.ff,cmd[i].ff.ss,cmd[i].ss);
		else if(cmd[i].ff.ff<0)
		{
			int l=-cmd[i].ff.ff,r=cmd[i].ff.ss;
			printendl(sum.query(r,r)+sum.query(l-1,l-1)-sum.query(l-1,r)-sum.query(r,l-1));
		}
	}
}
int main()
{
	get2(n,m);
	for(int i=1;i<=n;i++)get1(a[i]);
	for(int i=1;i<=m;i++)get3(tp[i],x[i],y[i]);
	solve();
	return 0;
}