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

int k,n,maxb,t,tb;
int cnt[100111],a[100111],dp[100111],ndp[100111],bit[100111];
void add(int x,int v){for(;x<=tb;x+=x&-x)bit[x]=max(bit[x],v);}
int query(int x){int ret=0;for(;x>0;x-=x&-x)ret=max(ret,bit[x]);return ret;}
void solve()
{
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=n;i++)
	{
		get1(a[i]);
		cnt[a[i]]++;
	}
	tb=0;for(int i=1;i<=maxb;i++)tb+=(cnt[i]>0);
	if(min(tb,n)<=t)
	{
		printf("%d\n",min(tb,n));
		return;
	}
	vector<int> v;for(int i=1;i<=n;i++)v.pb(a[i]);sort(v.begin(),v.end());v.erase(unique(v.begin(),v.end()),v.end());
	for(int i=1;i<=n;i++)a[i]=upper_bound(v.begin(),v.end(),a[i])-v.begin();
	tb=v.size()+1;
	for(int i=1;i<=n;i++)dp[i]=1;
	int ans=0;
	memset(bit,0,sizeof(bit));
	for(int _=0;_<t;_++)
	{
		for(int i=1;i<=n;i++)
		{
			int tans=query(a[i]-1)+1;
			ans=max(ans,tans);
			add(a[i],tans);
		}
	}
	printendl(ans);
}
int main()
{
	get2(k,n);get2(maxb,t);
	for(int i=1;i<=k;i++)solve();
	return 0;
}