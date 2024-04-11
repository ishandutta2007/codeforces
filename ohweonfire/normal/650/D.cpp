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

int dpl[400111],dpr[400111],bit[400111];
void modify(int x,int v){for(;x<400111;x+=x&-x)bit[x]=max(bit[x],v);}
int query(int x){int ret=0;for(;x;x-=x&-x)ret=max(ret,bit[x]);return ret;}

int n,m,h[400111],tk,ans[400111],have[400111];
bool kill[400111];
vector<int> vs;
vector<pii> q[400111];

int main()
{
	get2(n,m);
	for(int i=1;i<=n;i++){get1(h[i]);vs.pb(h[i]);}
	for(int i=1;i<=m;i++)
	{
		int a,b;get2(a,b);
		q[a].pb(mp(b,i));
	}
	vs.pb(0);sort(vs.begin(),vs.end());vs.erase(unique(vs.begin(),vs.end()),vs.end());
	for(int i=1;i<=n;i++)h[i]=lower_bound(vs.begin(),vs.end(),h[i])-vs.begin();
	int sz=(int)vs.size()-1;
	
	memset(bit,0,sizeof(bit));
	for(int i=1;i<=n;i++)
	{
		dpl[i]=query(h[i]-1)+1;
		modify(h[i],dpl[i]);
	}
	memset(bit,0,sizeof(bit));
	for(int i=n;i>=1;i--)
	{
		dpr[i]=query(sz-h[i])+1;
		modify(sz-h[i]+1,dpr[i]);
	}
	tk=query(sz);
	
	memset(bit,0,sizeof(bit));
	for(int i=1;i<=n;i++)
	{
		for(auto v:q[i])
		{
			int id=lower_bound(vs.begin(),vs.end(),v.ff)-vs.begin()-1;
			ans[v.ss]+=query(id);
		}
		modify(h[i],dpl[i]);
	}
	memset(bit,0,sizeof(bit));
	for(int i=n;i>=1;i--)
	{
		for(auto v:q[i])
		{
			int id=lower_bound(vs.begin(),vs.end(),v.ff+1)-vs.begin();
			ans[v.ss]+=query(sz-id+1)+1;
		}
		modify(sz-h[i]+1,dpr[i]);
	}
	
	for(int i=1;i<=n;i++)if(dpl[i]+dpr[i]==tk+1)
	{
		if(have[dpl[i]])have[dpl[i]]=-1;
		else have[dpl[i]]=i;
	}
	for(int i=1;i<=n;i++)if(have[i]>0)kill[have[i]]=1;
	for(int i=1;i<=n;i++)for(auto v:q[i])
	{
		if(!kill[i])ans[v.ss]=max(ans[v.ss],tk);
		else ans[v.ss]=max(ans[v.ss],tk-1);
	}
	for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
	return 0;
}