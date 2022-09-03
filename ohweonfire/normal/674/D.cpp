// This amazing code is by Eric Sunli Chen.
#include<bits/stdc++.h>
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

#define int long long
const int maxn=100111;

set<pair<LL,int> > sons[maxn],all;
int n,q,f[maxn],dgr[maxn];
LL t[maxn],val[maxn],mxv[maxn],mnv[maxn];

void reset_sons(int u)
{
	if((int)sons[u].size()==0)return;
	int lv=sons[u].begin()->ss,rv=sons[u].rbegin()->ss;
	all.erase(mp(val[lv]+t[u]/dgr[u],lv));
	all.erase(mp(val[rv]+t[u]/dgr[u],rv));
}
void set_sons(int u)
{
	if((int)sons[u].size()==0)return;
	int lv=sons[u].begin()->ss,rv=sons[u].rbegin()->ss;
	all.insert(mp(val[lv]+t[u]/dgr[u],lv));
	all.insert(mp(val[rv]+t[u]/dgr[u],rv));
}
void reset_val(int u)
{
	reset_sons(f[u]);
	sons[f[u]].erase(mp(val[u],u));
}
void set_val(int u)
{
	sons[f[u]].insert(mp(val[u],u));
	set_sons(f[u]);
}

signed main()
{
	get2(n,q);
	for(int i=1;i<=n;i++)get1(t[i]);
	for(int i=1;i<=n;i++)get1(f[i]);
	
	for(int i=1;i<=n;i++)dgr[f[i]]++;
	for(int i=1;i<=n;i++)
	{
		dgr[i]+=2;
		val[f[i]]+=t[i]/dgr[i];
		val[i]+=t[i]-t[i]/dgr[i]*(dgr[i]-1);
	}
	for(int i=1;i<=n;i++)sons[f[i]].insert(mp(val[i],i));
	for(int i=1;i<=n;i++)set_sons(i);
	
	for(int i=1,tp,x,y;i<=q;i++)
	{
		get1(tp);
		if(tp==1)
		{
			get2(x,y);
			
			reset_val(f[x]);
			reset_val(f[f[x]]);
			reset_sons(f[x]);
			sons[f[x]].erase(mp(val[x],x));
			
			val[f[x]]-=t[x]/dgr[x];
			
			val[f[x]]-=t[f[x]]-t[f[x]]/dgr[f[x]]*(dgr[f[x]]-1);
			val[f[f[x]]]-=t[f[x]]/dgr[f[x]];
			dgr[f[x]]--;
			val[f[x]]+=t[f[x]]-t[f[x]]/dgr[f[x]]*(dgr[f[x]]-1);
			val[f[f[x]]]+=t[f[x]]/dgr[f[x]];
			
			set_val(f[x]);
			set_val(f[f[x]]);
			set_sons(f[x]);
			
			f[x]=y;
			reset_val(f[x]);
			reset_val(f[f[x]]);
			reset_sons(f[x]);
			sons[f[x]].insert(mp(val[x],x));
			
			val[f[x]]-=t[f[x]]-t[f[x]]/dgr[f[x]]*(dgr[f[x]]-1);
			val[f[f[x]]]-=t[f[x]]/dgr[f[x]];
			dgr[f[x]]++;
			val[f[x]]+=t[f[x]]-t[f[x]]/dgr[f[x]]*(dgr[f[x]]-1);
			val[f[f[x]]]+=t[f[x]]/dgr[f[x]];
			
			val[f[x]]+=t[x]/dgr[x];
			
			set_val(f[x]);
			set_val(f[f[x]]);
			set_sons(f[x]);
		}
		else if(tp==2)
		{
			get1(x);y=f[x];
			printf("%lld\n",val[x]+t[y]/dgr[y]);
		}
		else printf("%lld %lld\n",all.begin()->ff,all.rbegin()->ff);
	}
	return 0;
}