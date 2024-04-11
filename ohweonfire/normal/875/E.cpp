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

int n,x[100111];
bool check(int v)
{
	set<int>s;
	if(abs(x[2]-x[1])>v)return false;
	s.insert(x[1]);
	for(int i=2;i<n;i++)
	{
		if(abs(x[i]-x[i+1])<=v)s.insert(x[i]);
		while(s.size()&&*s.begin()<x[i+1]-v)s.erase(*s.begin());
		while(s.size()&&*s.rbegin()>x[i+1]+v)s.erase(*s.rbegin());
		if(s.size()==0)return false;
	}
	return true;
}
int main()
{
	get3(n,x[1],x[2]);n+=2;
	for(int i=3;i<=n;i++)get1(x[i]);
	int l=abs(x[2]-x[1])-1,r=1000000000,mid;
	while(l<r-1)
	{
		mid=(l+r+1)>>1;
		if(check(mid))r=mid;else l=mid;
	}
	printendl(r);
	return 0;
}