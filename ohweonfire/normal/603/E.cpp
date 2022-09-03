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

struct edge
{
	int u,v,len,id;
	bool operator<(edge b)const{return mp(len,mp(u,v))<mp(b.len,mp(b.u,b.v));}
}e[300111],val[300111];

int n,m,ans[300111];
int f[100111],sz[100111],cnt,cur;
struct change
{
	int idu,idv,pre_f,pre_sz,pre_ans;
	void back()
	{
		cur=pre_ans;
		f[idu]=pre_f;
		sz[idv]=pre_sz;
	}
}q[300111];
int gf(int x){return x==f[x]?x:gf(f[x]);}
void un(int u,int v)
{
	u=gf(u);v=gf(v);if(u==v)return;
	if(sz[u]>sz[v])swap(u,v);
	q[++cnt]=change{u,v,f[u],sz[v],cur};
	if(sz[u]%2&&sz[v]%2)cur-=2;
	sz[v]+=sz[u];
	f[u]=v;
}

void solve(int l,int r,int lo,int hi)
{
	if(l>r)return;
	if(cur==0)
	{
		for(int i=l;i<=r;i++)ans[i]=lo;
		return;
	}
	int mid=(l+r)>>1,tans=hi,idl=lower_bound(val+1,val+m+1,edge{0,0,lo,0})-val,idr=lower_bound(val+1,val+m+1,edge{inf,inf,hi,inf})-val;
	int tmp=cnt;
	vector<edge>t;
	for(int i=idl;i<idr;i++)if(val[i].id<l)t.pb(val[i]);
	for(int i=l;i<=mid;i++)t.pb(e[i]);
	sort(t.begin(),t.end());
	for(int i=0;i<(int)t.size();i++)
	{
		un(t[i].u,t[i].v);
		if(cur==0)
		{
			tans=max(lo,t[i].len);
			break;
		}
	}
	ans[mid]=tans;
	while(cnt!=tmp)q[cnt--].back();
	for(int i=idl;i<idr;i++)if(val[i].id<l&&val[i].len<=tans)un(val[i].u,val[i].v);
	solve(l,mid-1,tans,hi);
	while(cnt!=tmp)q[cnt--].back();
	for(int i=l;i<=mid;i++)if(e[i].len<=lo)un(e[i].u,e[i].v);
	solve(mid+1,r,lo,tans);
	while(cnt!=tmp)q[cnt--].back();
}

int main()
{
	get2(n,m);
	if(n%2)
	{
		for(int i=1;i<=m;i++)puts("-1");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
		sz[i]=1;
	}
	cur=n;
	for(int i=1;i<=m;i++)
	{
		get3(e[i].u,e[i].v,e[i].len);
		e[i].id=i;
	}
	memcpy(val,e,sizeof(e));sort(val+1,val+m+1);
	
	solve(1,m,1,inf);
	for(int i=1;i<=m;i++)
	{
		if(ans[i]==inf)ans[i]=-1;
		printendl(ans[i]);
	}
	return 0;
}