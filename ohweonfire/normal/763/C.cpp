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

int m,n,a[100111];
set<int> s1,s2;

pii ans;
void solve()
{
	
	for(int i=2;i<=n;i++)
	{
		int d=a[i],le=0,ri=1;
		for(int j=1;j<n&&le+ri<n;j++)
			if(s1.find(1ll*j*d%m)==s1.end())break;
			else ri++;
		for(int j=1;j<n&&le+ri<n;j++)
			if(s1.find(1ll*(m-j)*d%m)==s1.end())break;
			else le++;
		if(le+ri==n)
		{
			ans=mp(1ll*(m-le)*d%m,d);
			return;
		}
	}
	puts("-1");
	exit(0);
}
int main()
{
	get2(m,n);
	for(int i=1;i<=n;i++)get1(a[i]);
	if(n==1||n==m)
	{
		printf("%d %d\n",a[1],n-1);
		return 0;
	}
	bool flag=0;
	if(m-n<n)
	{
		flag=1;
		for(int i=1;i<=n;i++)s1.insert(a[i]);
		for(int i=0;i<m;i++)if(s1.find(i)==s1.end())s2.insert(i);
		s2.swap(s1);
		int nn=0;for(set<int>::iterator it=s1.begin();it!=s1.end();it++)a[++nn]=*it;
		n=nn;
	}
	if(n==1)
	{
		printf("%d %d\n",(a[1]+1)%m,1);
		return 0;
	}
	int sub=a[1];
	for(int i=2;i<=n;i++)a[i]=(a[i]-a[1]+m)%m;
	s1.clear();
	for(int i=2;i<=n;i++)s1.insert(a[i]);
	
	solve();
	ans.ff=(ans.ff+sub)%m;
	if(flag)ans.ff=(ans.ff+1ll*ans.ss*n%m+m)%m;
	printf("%d %d\n",ans.ff,ans.ss);
	return 0;
}