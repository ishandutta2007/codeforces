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

const int maxn=100111;
int n,m,k,a[maxn],sz[maxn];
pair<int,pii> es[maxn];
int f[maxn];int gf(int x){return x==f[x]?x:f[x]=gf(f[x]);}
int main()
{
	get3(n,m,k);
	for(int i=1;i<=k;i++)
	{
		get1(a[i]);
		sz[a[i]]=1;
	}
	for(int i=1,u,v,w;i<=m;i++)
	{
		get3(u,v,w);
		es[i]=mp(w,mp(u,v));
	}
	sort(es+1,es+m+1);
	int ans=0;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++)
	{
		int u=es[i].ss.ff,v=es[i].ss.ss;
		u=gf(u);v=gf(v);
		if(u==v)continue;
		f[u]=v;sz[v]+=sz[u];
		if(sz[u]!=k&&sz[u]!=0)ans=es[i].ff;
	}
	for(int i=1;i<=k;i++)printf("%d ",ans);
	return 0;
}