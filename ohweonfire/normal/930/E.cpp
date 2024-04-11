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

const int mod=1e9+7;
int power(int x,int y){int ret=1;do{if(y&1)ret=1ll*ret*x%mod;x=1ll*x*x%mod;}while(y>>=1);return ret;}
inline void add(int&x,const int &y){x+=y;if(x>=mod)x-=mod;}

int n,m,k,mxa[400111],mxb[400111];
pii a[100111],b[100111];
int dp[2][400111];

int main()
{
	get3(k,n,m);
	vector<int> v;v.pb(0);v.pb(k);
	for(int i=1;i<=n;i++)
	{
		get2(a[i].ff,a[i].ss);a[i].ff--;
		v.pb(a[i].ff);v.pb(a[i].ss);
	}
	for(int i=1;i<=m;i++)
	{
		get2(b[i].ff,b[i].ss);b[i].ff--;
		v.pb(b[i].ff);v.pb(b[i].ss);
	}
	sort(v.begin(),v.end());v.erase(unique(v.begin(),v.end()),v.end());
	memset(mxa,-1,sizeof(mxa));memset(mxb,-1,sizeof(mxb));
	for(int i=1;i<=n;i++)
	{
		a[i].ff=lower_bound(v.begin(),v.end(),a[i].ff)-v.begin();
		a[i].ss=lower_bound(v.begin(),v.end(),a[i].ss)-v.begin();
		mxa[a[i].ss]=max(mxa[a[i].ss],a[i].ff);
	}
	for(int i=1;i<=m;i++)
	{
		b[i].ff=lower_bound(v.begin(),v.end(),b[i].ff)-v.begin();
		b[i].ss=lower_bound(v.begin(),v.end(),b[i].ss)-v.begin();
		mxb[b[i].ss]=max(mxb[b[i].ss],b[i].ff);
	}
	int cur[2]={},s[2]={1,0},ts[2]={};dp[0][0]=1;
	for(int i=0;i<(int)v.size()-1;i++)
	{
		ts[0]=s[0];ts[1]=s[1];
		add(s[0],mod-dp[0][i]);
		add(s[0],mod-dp[0][i+1]);
		add(s[1],mod-dp[1][i]);
		add(s[1],mod-dp[1][i+1]);
		add(dp[0][i+1],1ll*(ts[0]+ts[1])*(power(2,v[i+1]-v[i]-1)-1)%mod);
		add(dp[1][i+1],1ll*(ts[0]+ts[1])*(power(2,v[i+1]-v[i]-1)-1)%mod);
		add(dp[0][i],ts[1]);
		add(dp[1][i],ts[0]);
		add(s[0],dp[0][i]);
		add(s[0],dp[0][i+1]);
		add(s[1],dp[1][i]);
		add(s[1],dp[1][i+1]);
		while(cur[0]<=mxa[i+1])add(s[0],mod-dp[0][cur[0]++]);
		while(cur[1]<=mxb[i+1])add(s[1],mod-dp[1][cur[1]++]);
//		printf("i= %d s0= %d s1= %d mx= %d %d\n",i,s[0],s[1],mxa[i],mxb[i]);
	}
	int ans=0;add(ans,s[0]);add(ans,s[1]);
	printendl(ans);
	return 0;
}