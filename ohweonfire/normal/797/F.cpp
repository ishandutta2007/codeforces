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

const int maxn=5111;
int n,m,p[maxn],c[maxn],x[maxn];

int sum=0;
LL dp[maxn*2],ndp[maxn*2];
void add_hole(LL p,int c)
{
	sum-=c;
	while(c--)
	{
		for(int i=1;i<=10002;i++)
		{
			if(i<=5001)dp[i-1]=min(dp[i-1],dp[i]-p);
			if(i>5001)dp[i-1]=min(dp[i-1],dp[i]+p);
		}
	}
}
void add_mouse(LL p)
{
	memset(ndp,inf,sizeof(ndp));
	for(int i=1;i<=10002;i++)
	{
		if(i<5001)ndp[i+1]=min(ndp[i+1],dp[i]+p);
		if(i>=5001)ndp[i+1]=min(ndp[i+1],dp[i]-p);
	}
	memcpy(dp,ndp,sizeof(dp));
	sum++;
}

int c1[maxn],c2[maxn];
int main()
{
	get2(n,m);
	
	vector<pii> vs;
	for(int i=1;i<=n;i++)get1(x[i]);
	for(int i=1;i<=m;i++)
	{
		get2(p[i],c[i]);
		vs.pb(mp(p[i],i));
	}
	sort(vs.begin(),vs.end());
	sort(x+1,x+n+1);
	for(int i=1;i<=n;i++)
	{
		for(auto v:vs)
		{
			int id=v.ss;
			if(p[id]>=x[i]&&c1[id]<c[id])
			{
				c1[id]++;
				break;
			}
		}
	}
	reverse(vs.begin(),vs.end());
	for(int i=n;i>=1;i--)
	{
		for(auto v:vs)
		{
			int id=v.ss;
			if(p[id]<=x[i]&&c2[id]<c[id])
			{
				c2[id]++;
				break;
			}
		}
	}
	
	for(int i=1;i<=n;i++)vs.pb(mp(x[i],0));
	sort(vs.begin(),vs.end());
	
	memset(dp,inf,sizeof(dp));dp[5001]=0;
	for(int i=0;i<(int)vs.size();i++)
	{
		if(vs[i].ss==0)add_mouse(vs[i].ff);
		else add_hole(vs[i].ff,min(c[vs[i].ss],c1[vs[i].ss]+c2[vs[i].ss]));
	}
	
	LL ans=dp[5001];
	if(sum>0)ans=-1;
	printendl(ans);
	return 0;
}