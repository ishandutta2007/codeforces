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

namespace bit
{
	int bit[400111];
	void add(int x,int v){for(;x<400111;x+=x&-x)bit[x]+=v;}
	int query(int x){int ret=0;for(;x;x-=x&-x)ret+=bit[x];return ret;}
	int getpos(int rk)
	{
		int ret=0;
		for(int i=18;i>=0;i--)if(ret|(1<<i)<400111&&bit[ret|(1<<i)]<rk)
		{
			ret|=1<<i;
			rk-=bit[ret];
		}
		return ret+1;
	}
};

int f[200111],n;LL len[200111];
int gf(int x){return x==f[x]?x:f[x]=gf(f[x]);}

vector<int>vs;
int x[200111],y[200111],xx[200111],yy[200111];

set<pair<pii,int> >sweep;
struct event
{
	int time,op,i;//op=1 add;op=0 query;op=-1 del;
	bool operator <(const event&b)const
	{
		if(time!=b.time)return time<b.time;
		return op>b.op;
	}
	void process()
	{
//		printf("time= %d %d id= %d\n",time,op,i);
		if(op==1)
		{
			auto pos=sweep.upper_bound(mp(mp(y[i],inf),0));
			if(pos!=sweep.begin())
			{
				pos--;
				if(pos->ff.ss>=y[i])
				{
					int rk=bit::query(y[i]),pre=bit::getpos(rk),nxt=bit::getpos(rk+1);
					sweep.insert(mp(mp(pos->ff.ff,pre),pos->ss));
					sweep.insert(mp(mp(nxt,pos->ff.ss),pos->ss));
					sweep.erase(pos);
				}
			}
			bit::add(y[i],1);
			sweep.insert(mp(mp(y[i],y[i]),i));
		}
		else if(op==-1)
		{
			auto pos=sweep.lower_bound(mp(mp(y[i],inf),0));pos--;
			if(pos->ff.ff==y[i]&&pos->ff.ss==y[i])sweep.erase(pos);
			else if(pos->ff.ff==y[i])
			{
				int rk=bit::query(y[i]),nxt=bit::getpos(rk+1);
				sweep.insert(mp(mp(nxt,pos->ff.ss),pos->ss));
				sweep.erase(pos);
			}
			else if(pos->ff.ss==y[i])
			{
				int rk=bit::query(y[i]),pre=bit::getpos(rk-1);
				sweep.insert(mp(mp(pos->ff.ff,pre),pos->ss));
				sweep.erase(pos);
			}
			bit::add(y[i],-1);
		}
		else
		{
			int inter=bit::query(yy[i])-bit::query(y[i]-1);
			len[i]-=inter;
			if(inter==0)return;
			auto pl=sweep.lower_bound(mp(mp(y[i],inf),0));
			auto pr=sweep.lower_bound(mp(mp(yy[i],inf),0));
			if(pl!=sweep.begin())
			{
				pl--;
				if(pl->ff.ss<y[i])pl++;
			}
			if(pl==pr)return;
			vector<int>all;
			for(auto p=pl;p!=pr;p++)all.pb(gf(p->ss));
			sort(all.begin(),all.end());all.erase(unique(all.begin(),all.end()),all.end());
			for(auto&x:all)
			{
				f[x]=i;
				len[i]+=len[x]+1;
			}
			int nl=pl->ff.ff,nr=(--pr)->ff.ss;
			sweep.erase(pl,(++pr));
			sweep.insert(mp(mp(nl,nr),i));
		}
//		puts("\nsweepline now:");
//		for(auto x:sweep)printf("l= %d r= %d f= %d\n",vs[x.ff.ff],vs[x.ff.ss],gf(x.ss));
//		for(int i=1;i<=n;i++)if(f[i]==i)printf("comp %d len= %I64d\n",i,len[i]);
//		puts("");
	}
};
event a[400111];int tot;

int main()
{
	get1(n);
	for(int i=1;i<=n;i++)
	{
		get2(x[i],y[i]);
		get2(xx[i],yy[i]);
		f[i]=i;len[i]=xx[i]+yy[i]-x[i]-y[i];
		vs.pb(y[i]);vs.pb(yy[i]);
	}
	vs.pb(-inf);sort(vs.begin(),vs.end());vs.erase(unique(vs.begin(),vs.end()),vs.end());
	for(int i=1;i<=n;i++)
	{
		y[i]=lower_bound(vs.begin(),vs.end(),y[i])-vs.begin();
		yy[i]=lower_bound(vs.begin(),vs.end(),yy[i])-vs.begin();
		if(x[i]==xx[i])a[++tot]=event{x[i],0,i};
		else
		{
			a[++tot]=event{x[i],1,i};
			a[++tot]=event{xx[i],-1,i};
		}
	}
	sort(a+1,a+tot+1);
	
	for(int i=1;i<=tot;i++)a[i].process();
	assert((int)sweep.size()==0);
	
	LL ans=0;for(int i=1;i<=n;i++)if(f[i]==i)ans=max(ans,len[i]);
	printendl(ans);
	return 0;
}