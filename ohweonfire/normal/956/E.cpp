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

int n,l,r,sum,a[10111],b[10111],dp[10111],csum;
void update(int x,int v)
{
	for(int i=csum;i>=0;i--)dp[i+x]=max(dp[i+x],dp[i]+(v&&l<=i+x&&i+x<=r));
	csum+=x;
}
int main()
{
	get3(n,l,r);
	for(int i=1;i<=n;i++)get1(a[i]);
	for(int i=1;i<=n;i++)get1(b[i]);
	for(int i=1;i<=n;i++)sum+=a[i];
	for(int i=1;i<=sum;i++)dp[i]=-inf;
	swap(l,r);l=sum-l;r=sum-r;
	vector<int>vs;
	for(int i=1;i<=n;i++)
	{
		if(!b[i])update(a[i],0);
		else vs.pb(-a[i]);
	}
	sort(vs.begin(),vs.end());
	for(auto&v:vs)update(-v,1);
	printf("%d\n",*max_element(dp,dp+sum+1));
	return 0;
}