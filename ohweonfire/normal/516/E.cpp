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
typedef vector<int> vi;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

const int maxn=100111;
int n,m,cn,cm,g,x[maxn],y[maxn];
bool have[maxn<<1];

vector<pii> vs[maxn<<1];

void ext_gcd(int m,int n,int&a,int&b)
{
	if(n==0)
	{
		a=1;b=0;
		return;
	}
	int aa,bb;
	ext_gcd(n,m%n,aa,bb);
	a=bb;b=aa-bb*(m/n);
}

LL ans;
void calc()
{
	int tn=n/g,tm=m/g,invm,invn;
	ext_gcd(tn,tm,invn,invm);
	invn=(invn%tm+tm)%tm;
	invm=(invm%tn+tn)%tn;
	set<int> sx;
	for(int i=0;i<cn;i++)sx.insert(x[i]);
	for(int i=0;i<g;i++)vs[i].clear();
	for(int i=0;i<cn;i++)vs[x[i]%g].pb(mp(x[i],x[i]));
	for(int i=0;i<cm;i++)vs[y[i]%g].pb(mp(y[i]%n,y[i]));
	
	for(int i=0;i<g;i++)if((int)vs[i].size())
	{
		sort(vs[i].begin(),vs[i].end());
		int nn=0;
		for(int j=0;j<(int)vs[i].size();j++)if(nn==0||vs[i][j].ff!=vs[i][nn-1].ff)vs[i][nn++]=vs[i][j];
		vs[i].resize(nn);
		
		for(int j=0;j<nn;j++)
		{
			if(sx.find(vs[i][j].ff)==sx.end())ans=max(ans,vs[i][j].ss+0ll);
			int q=vs[i][j].ff-i;q/=g;
			q=(LL)q*invm%tn;
			vs[i][j].ff=q;
		}
		sort(vs[i].begin(),vs[i].end());
		
		LL mn=Linf;
		for(int j=0;j<nn;j++)mn=min(mn,vs[i][j].ss-(LL)(vs[i][j].ff-tn)*m);
		int lastv=vs[i][nn-1].ff-tn;
		for(int j=0;j<nn;j++)
		{
//			printf("lastv= %d\n",lastv);
			if(lastv<vs[i][j].ff-1)ans=max(ans,(LL)(vs[i][j].ff-1)*m+mn);
			lastv=vs[i][j].ff;
			mn=min(mn,vs[i][j].ss-(LL)vs[i][j].ff*m);
		}
	}
}

int main()
{
	get2(n,m);
	get1(cn);for(int i=0;i<cn;i++)get1(x[i]);
	get1(cm);for(int i=0;i<cm;i++)get1(y[i]);
	
	g=__gcd(n,m);
	if(g>cn+cm)
	{
		puts("-1");
		return 0;
	}
	
	for(int i=0;i<cn;i++)have[x[i]%g]=1;
	for(int i=0;i<cm;i++)have[y[i]%g]=1;
	for(int i=0;i<g;i++)if(!have[i])
	{
		puts("-1");
		return 0;
	}
	
	
	calc();
	swap(n,m);swap(cn,cm);swap(x,y);
	calc();
	
	printf("%lld\n",ans);
	return 0;
}