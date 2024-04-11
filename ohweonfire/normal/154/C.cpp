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

const uLL base=23333333;
int n,m;
vector<int> g[1000111];
uLL hsy[1000111],thsy[1000111],power[1000111];
int main()
{
	power[0]=1;for(int i=1;i<1000111;i++)power[i]=power[i-1]*base;
	get2(n,m);
	for(int i=1,u,v;i<=m;i++)
	{
		get2(u,v);
		g[u].pb(v);
		g[v].pb(u);
	}
	LL ans=0;
	for(int i=1;i<=n;i++)
	{
		hsy[i]=0;
		for(int j=0;j<(int)g[i].size();j++)
			hsy[i]+=power[g[i][j]];
		thsy[i]=hsy[i]+power[i];
	}
	sort(hsy+1,hsy+n+1);
	int cur=0;
	for(int i=1;i<=n;i++)
	{
		cur++;
		if(i==n||hsy[i]!=hsy[i+1])
		{
			ans+=1ll*cur*(cur-1)/2;
			cur=0;
		}
	}
	sort(thsy+1,thsy+n+1);
	cur=0;
	for(int i=1;i<=n;i++)
	{
		cur++;
		if(i==n||thsy[i]!=thsy[i+1])
		{
			ans+=1ll*cur*(cur-1)/2;
			cur=0;
		}
	}
	printendl(ans);
	return 0;
}