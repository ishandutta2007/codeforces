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

int n,sufmx[100111],sufmn[100111];
LL calc(vector<pii>&v)
{
	sort(v.begin(),v.end());
	int sz=(int)v.size();
	sufmn[sz]=inf;sufmx[sz]=0;
	int mn=inf,mx=0,cur=0;
	for(int i=sz-1;i>=0;i--)
	{
		sufmx[i]=max(sufmx[i+1],v[i].ss);
		sufmn[i]=min(sufmn[i+1],v[i].ss);
	}
	LL ret=0;
	for(int i=0;i<=200000;i++)
	{
		while(cur<sz&&v[cur].ff<=i)
		{
			mx=max(mx,v[cur].ss);
			mn=min(mn,v[cur].ss);
			cur++;
		}
		ret+=max(0,min(mx,sufmx[cur])-max(mn,sufmn[cur]));
	}
	return ret;
}
int main()
{
	get1(n);
	vector<pii>v[2];
	for(int i=1;i<=n;i++)
	{
		int x,y;get2(x,y);x+=100000;y+=100000;
		v[(x+y)&1].pb(mp(x+y>>1,x-y+200000>>1));
	}
	printendl(calc(v[0])+calc(v[1]));
	return 0;
}