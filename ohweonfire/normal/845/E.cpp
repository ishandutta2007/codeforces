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

int n,m,k,tx[555],ty[555],sum[1111][1111];
bool check(int x)
{
	memset(sum,0,sizeof(sum));
	vector<int> vx={0,1,n+1},vy={0,1,m+1};
	for(int i=1;i<=k;i++)
	{
		vx.pb(max(1,tx[i]-x));vx.pb(min(n+1,tx[i]+x+1));
		vy.pb(max(1,ty[i]-x));vy.pb(min(m+1,ty[i]+x+1));
	}
	sort(vx.begin(),vx.end());vx.erase(unique(vx.begin(),vx.end()),vx.end());
	sort(vy.begin(),vy.end());vy.erase(unique(vy.begin(),vy.end()),vy.end());
	int xl,xr,yl,yr;
	for(int i=1;i<=k;i++)
	{
		xl=lower_bound(vx.begin(),vx.end(),max(1,tx[i]-x))-vx.begin();
		xr=lower_bound(vx.begin(),vx.end(),min(n+1,tx[i]+x+1))-vx.begin();
		yl=lower_bound(vy.begin(),vy.end(),max(1,ty[i]-x))-vy.begin();
		yr=lower_bound(vy.begin(),vy.end(),min(m+1,ty[i]+x+1))-vy.begin();
		sum[xl][yl]++;sum[xr][yr]++;sum[xl][yr]--;sum[xr][yl]--;
	}
	xl=n;xr=0;yl=m;yr=0;
	for(int i=1;i<(int)vx.size()-1;i++)for(int j=1;j<(int)vy.size()-1;j++)
	{
		sum[i][j]+=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
		if(sum[i][j]==0)
		{
			xl=min(xl,vx[i]);xr=max(xr,vx[i+1]);
			yl=min(yl,vy[j]);yr=max(yr,vy[j+1]);
		}
	}
	if(xr-xl<=2*x+1&&yr-yl<=2*x+1)return true;
	return false;
}
int main()
{
	get3(n,m,k);
	for(int i=1;i<=k;i++)get2(tx[i],ty[i]);
	
	int l=-1,r=1000000001,mid;
	while(l<r-1)
	{
		mid=(l+r+1)>>1;
		if(check(mid))r=mid;
		else l=mid;
	}
	printendl(r);/**/
	return 0;
}