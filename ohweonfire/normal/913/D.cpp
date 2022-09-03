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

int n,T,a[200111],t[200111],nt[200111];
bool cmp(int x,int y){return t[x]<t[y];}
bool check(int x)
{
	int m=0;
	for(int i=1;i<=n;i++)if(a[i]>=x)
		nt[++m]=i;
	if(x>m)return false;sort(nt+1,nt+m+1,cmp);
	int sum=0;for(int i=1;i<=x;i++)sum+=t[nt[i]];
	return sum<=T;
}
int main()
{
	get2(n,T);for(int i=1;i<=n;i++)get2(a[i],t[i]);
	int l=0,r=n+1,mid;
	while(l<r-1)
	{
		mid=(l+r)>>1;
		if(check(mid))l=mid;
		else r=mid;
	}
	check(l);printf("%d\n%d\n",l,l);
	for(int i=1;i<=l;i++)printf("%d ",nt[i]);puts("");
	return 0;
}