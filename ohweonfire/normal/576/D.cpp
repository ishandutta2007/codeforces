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

vector<pair<int,pii> >vs;
int n,m;
struct adj
{
	bitset<150>a[150],b[150];
	void set(int u,int v){a[u].set(v);b[v].set(u);}
};
adj mult(const adj&x,const adj&y)
{
	adj z;
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)if((x.a[i]&y.b[j]).any())z.set(i,j);
	return z;
}
bitset<150> mult2(const bitset<150>&x,const adj&y)
{
	bitset<150> z;
	for(int i=0;i<n;i++)if((x&y.b[i]).any())z.set(i);
	return z;
}
adj qpow(adj x,int y)
{
	adj ret;
	for(int i=0;i<n;i++)ret.set(i,i);
	while(y)
	{
		if(y&1)ret=mult(ret,x);
		x=mult(x,x);
		y>>=1;
	}
	return ret;
}

int main()
{
	get2(n,m);
	for(int i=0,a,b,c;i<m;i++)
	{
		get3(a,b,c);a--;b--;
		vs.pb(mp(c,mp(a,b)));
	}
	vs.pb(mp(1000000000+n,mp(0,0)));
	sort(vs.begin(),vs.end());
	if(vs[0].ff)
	{
		puts("Impossible");
		return 0;
	}
	
	adj cur,tran,ncur;for(int i=0;i<n;i++)cur.set(i,i);
	int curt=0;
	for(int i=0;i<(int)vs.size();i++)
	{
		if(curt!=vs[i].ff)
		{
			bitset<150> now=cur.a[0];
			for(int j=curt+1;j<=curt+n&&j<=vs[i].ff;j++)
			{
				now=mult2(now,tran);
				if(now[n-1])
				{
					printendl(j);
					return 0;
				}
			}
			cur=mult(cur,qpow(tran,vs[i].ff-curt));
			curt=vs[i].ff;
		}
		tran.set(vs[i].ss.ff,vs[i].ss.ss);
	}
	puts("Impossible");
	return 0;
}