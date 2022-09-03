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

#define ls (t<<1)
#define rs ((t<<1)|1)
int mn[600111];
void add(int p,int v,int tl,int tr,int t)
{
	if(tl==tr)
	{
		mn[t]+=v;
		return;
	}
	int mid=(tl+tr)>>1;
	if(p<=mid)add(p,v,tl,mid,ls);
	else add(p,v,mid+1,tr,rs);
	mn[t]=min(mn[ls],mn[rs]);
}

int n,m,a[200111],b[200111];

int main()
{
	get2(n,m);
	for(int i=1;i<=n;i++)get1(a[i]);
	int sum=0;
	for(int i=1;i<=m;i++)
	{
		get1(b[i]);
		sum+=b[i];
		add(i,-b[i],1,m,1);
	}
	
	int cur=1,ans=inf;
	for(int i=1;i<=n;i++)
	{
		while(cur<=n&&mn[1]<0)
		{
			add(a[cur],1,1,m,1);
			cur++;
		}
		if(mn[1]>=0)ans=min(ans,cur-i-sum);
		add(a[i],-1,1,m,1);
	}
	if(ans==inf)ans=-1;
	printendl(ans);
	
	return 0;
}