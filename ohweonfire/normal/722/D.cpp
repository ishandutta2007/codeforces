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

template<typename T> inline void updmax(T &x,const T y){if(x<y)x=y;}
template<typename T> inline void updmin(T &x,const T y){if(x>y)x=y;}

int n;
pii p[100111];
int ans[100111];
bool check(int x)
{
	set<int> s;
	for(int i=1;i<=n;i++)
	{
		int t=p[i].ff;
		while(t>x)t>>=1;
		while(t>0&&s.count(t))t>>=1;
		if(t==0)return false;
		s.insert(t);
		ans[p[i].ss]=t;
	}
	return true;
}
int main()
{
	get1(n);
	for(int i=1;i<=n;i++)
	{
		get1(p[i].ff);
		p[i].ss=i;
	}
	sort(p+1,p+n+1);
	reverse(p+1,p+n+1);
	int l=0,r=1e9+1;
	while(l<r-1)
	{
		int mid=(l+r)>>1;
		if(check(mid))r=mid;
		else l=mid;
	}
	check(r);
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
	return 0;
}