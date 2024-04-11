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

vector<int> g[100111];
int n,a[100111],bit[100111];
void add(int x,int v)
{
	for(;x<100111;x+=x&-x)
		bit[x]+=v;
}
int query(int x)
{
	int ret=0;
	for(;x>0;x-=x&-x)
		ret+=bit[x];
	return ret;
}
LL ans;
int main()
{
	get1(n);
	for(int i=1;i<=n;i++)
	{
		get1(a[i]);
		g[a[i]].pb(i);
	}
	int cur=1;ans=1;
	for(int i=1;i<=n;i++)add(i,1);
	for(int i=1;i<100111;i++)
	{
		int pos=upper_bound(g[i].begin(),g[i].end(),cur-1)-g[i].begin();
		for(int j=pos;j<(int)g[i].size();j++)
		{
			ans+=query(g[i][j])-query(cur);
			cur=g[i][j];
			add(cur,-1);
		}
		for(int j=0;j<pos;j++)
		{
			if(g[i][j]<cur)ans+=query(g[i][j])+query(100111)-query(cur);
			else ans+=query(g[i][j])-query(cur);
			cur=g[i][j];
			add(cur,-1);
		}
	}
	printendl(ans);
	return 0;
}