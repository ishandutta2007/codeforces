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

int n,ans,t[10],curt[10],par[10];
LL a[10],cur[10];
int getp(LL a)
{
	int ret=0;
	for(int i=2;1ll*i*i<=a;i++)
		while(a%i==0)
		{
			ret++;
			a/=i;
		}
	if(a>1)ret++;
	return ret;
}
void dfs(int x,bool split=0)
{
	if(x==n+1)
	{
		int s=n+split;
		for(int i=1;i<=n;i++)if(t[i]>1||curt[i]>1)s+=curt[i];
		ans=min(ans,s);
		return;
	}
	par[x]=0;
	dfs(x+1,(x>1));
	for(int i=1;i<x;i++)if(cur[i]%a[x]==0)
	{
		cur[i]/=a[x];
		curt[i]-=t[x];
		par[x]=i;
		dfs(x+1,split);
		cur[i]*=a[x];
		curt[i]+=t[x];
	}
}
int main()
{
	get1(n);
	for(int i=1;i<=n;i++)
		get1(a[i]);
	sort(a+1,a+n+1);reverse(a+1,a+n+1);
	memcpy(cur,a,sizeof(a));
	for(int i=1;i<=n;i++)t[i]=curt[i]=getp(a[i]);
	ans=inf;
	dfs(1);
	printf("%d\n",ans);
	return 0;
}