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

const int maxn=233;

int n,l[maxn],a[maxn],dp[maxn][maxn];
vector<pair<pii,int> >vs;
int main()
{
	get1(n);
	for(int i=1;i<=n;i++)
	{
		get2(l[i],a[i]);
		vs.pb(mp(mp(l[i]-a[i],l[i]),i));
		vs.pb(mp(mp(l[i],l[i]+a[i]),i));
	}
	vs.pb(mp(mp(-inf,-inf),0));
	sort(vs.begin(),vs.end());
	
	memset(dp,-1,sizeof(dp));int sz=(int)vs.size()-1;
	for(int i=1;i<=sz;i++)dp[i][0]=vs[i].ff.ss-vs[i].ff.ff;
	
	int ans=0;
//	for(int i=1;i<=sz;i++)printf("i= %d l= %d r= %d id= %d\n",i,vs[i].ff.ff,vs[i].ff.ss,vs[i].ss);
	for(int i=1;i<=sz;i++)for(int last=0;last<i;last++)if(dp[i][last]!=-1)
	{
		ans=max(ans,dp[i][last]);
//		printf("i= %d last= %d dp= %d\n",i,last,dp[i][last]);
		for(int nxt=i+1;nxt<=sz;nxt++)
		{
			if(vs[i].ff.ss>=vs[nxt].ff.ss)continue;
			if(vs[nxt].ff.ff<=vs[last].ff.ss)continue;
			if(vs[i].ss==vs[nxt].ss)continue;
			int nv=vs[nxt].ff.ss-max(vs[nxt].ff.ff,vs[i].ff.ss);
			dp[nxt][i]=max(dp[nxt][i],dp[i][last]+nv);
		}
	}
	printendl(ans);
	return 0;
}