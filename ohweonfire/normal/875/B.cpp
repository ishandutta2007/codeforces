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

int n,p[300111],a[300111],f[300111],sz[300111];
int gf(int x){return x==f[x]?x:f[x]=gf(f[x]);}
void un(int x,int y)
{
	x=gf(x);y=gf(y);
	if(x==y)return;
	f[x]=y;sz[y]+=sz[x];
}
int main()
{
	get1(n);
	for(int i=1;i<=n;i++){f[i]=i;sz[i]=1;}
	for(int i=1;i<=n;i++)get1(p[i]);
	printf("1 ");
	for(int i=1;i<=n;i++)
	{
		if(a[p[i]-1])un(p[i]-1,p[i]);
		if(a[p[i]+1])un(p[i]+1,p[i]);
		a[p[i]]=1;
		printf("%d ",i-a[n]*sz[gf(n)]+1);
	}
	return 0;
}