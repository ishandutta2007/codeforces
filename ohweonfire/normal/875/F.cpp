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

int n,m,a[200111],b[200111],w[200111],ord[200111];
bool cmp(int x,int y){return w[x]>w[y];}
int f[200111],ok[200111];int gf(int x){return x==f[x]?x:f[x]=gf(f[x]);}
int main()
{
	get2(n,m);
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++)
	{
		get3(a[i],b[i],w[i]);
		ord[i]=i;
	}
	sort(ord+1,ord+m+1,cmp);
	int ans=0;
	for(int _=1,i;_<=m;_++)
	{
		i=ord[_];
		int x=gf(a[i]),y=gf(b[i]);
		if(ok[x]&&ok[y])continue;
		if(ok[x])swap(x,y);
		ans+=w[i];
		if(x==y)ok[x]=1;
		else f[x]=y;
	}
	printendl(ans);
	return 0;
}