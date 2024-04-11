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
typedef pair<LL,LL> pii;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

const int mod=998244353;
vector<pii> va,vb,vc;
void add(vector<pii>&v,LL l,LL r)
{
//	printf("l= %lld r= %lld\n",l,r);
	r++;
	while(l+(l&-l)<=r)
	{
		v.pb(mp(l,l+(l&-l)-1));
		l+=l&-l;
	}
	while(r-(r&-r)>=l)
	{
		v.pb(mp(r-(r&-r),r-1));
		r-=r&-r;
	}
	if(l!=r)puts("baojing");
}
void work(vector<pii>&v)
{
	sort(v.begin(),v.end());
	vector<pii> nv;
	LL mx=-Linf;
	for(int i=0;i<(int)v.size();i++)
	{
		if(mx>=v[i].ss)continue;
		nv.pb(mp(max(mx+1,v[i].ff),v[i].ss));
		mx=v[i].ss;
	}
	v=nv;
}

void work2(vector<pii>&v)
{
	vector<pii> nv;
	for(auto vv:v)add(nv,vv.ff,vv.ss);
	v=nv;
}

const int maxn=10000111;
int go[maxn][2],tot,ans;
bool ok[maxn];
void ins(LL val,int k)
{
	int cur=1;if(ok[cur])return;
	for(int i=59;i>=k;i--)
	{
		int v=((val>>i)&1);
		if(ok[cur])return;
		if(!go[cur][v])go[cur][v]=++tot;
		cur=go[cur][v];
	}
	ok[cur]=1;
}

void dfs(int x,LL l,int d)
{
	if(ok[x])
	{
		LL r=l+(1ll<<d)-1;
		l%=mod;
		r%=mod;
		int len=(r-l+mod+1)%mod;
		ans=(ans+(LL)(l+r)*len%mod*(mod+1)/2)%mod;
		return;
	}
	if(go[x][0])dfs(go[x][0],l,d-1);
	if(go[x][1])dfs(go[x][1],l|(1ll<<d-1),d-1);
}

int n,m;
int main()
{
	tot++;
	get1(n);
	LL L,R;
	for(int i=1;i<=n;i++)
	{
		get2(L,R);
		va.pb(mp(L,R));
	}
	get1(m);
	for(int i=1;i<=m;i++)
	{
		get2(L,R);
		vb.pb(mp(L,R));
	}
	work(va);
	work(vb);
	work2(va);
	work2(vb);
	for(int i=0;i<(int)va.size();i++)for(int j=0;j<(int)vb.size();j++)
	{
		LL mn=Linf,mx=0;
		mx=max(mx,va[i].ff^vb[j].ff);
		mx=max(mx,va[i].ff^vb[j].ss);
		mx=max(mx,va[i].ss^vb[j].ff);
		mx=max(mx,va[i].ss^vb[j].ss);
		mn=min(mn,va[i].ff^vb[j].ff);
		mn=min(mn,va[i].ff^vb[j].ss);
		mn=min(mn,va[i].ss^vb[j].ff);
		mn=min(mn,va[i].ss^vb[j].ss);
		LL co=mn&mx;
		ins(co,__builtin_ctzll(~(mx^mn)));
//		printf("mn= %lld mx= %lld\n",mn,mx);
	}
	dfs(1,0,60);
	printendl(ans);
	return 0;
}