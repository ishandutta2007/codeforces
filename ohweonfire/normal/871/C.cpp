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

const int mod=1e9+7;
int power(int x,int y)
{
	int ret=1;
	while(y)
	{
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;
		y>>=1;
	}
	return ret;
}
map<int,int> idx,idy;int tot;
int getid(map<int,int>&id,int x)
{
	int&v=id[x];if(v==0)v=++tot;
	return v;
}

int n,x[100111],y[100111],f[200111],szv[200111],sze[200111];
int gf(int x){return x==f[x]?x:f[x]=gf(f[x]);}
int main()
{
	for(int i=0;i<200111;i++)f[i]=i;
	get1(n);
	for(int i=1;i<=n;i++)
	{
		get2(x[i],y[i]);
		x[i]=getid(idx,x[i]);y[i]=getid(idy,y[i]);
		f[gf(x[i])]=gf(y[i]);
	}
	for(int i=1;i<=tot;i++)szv[gf(i)]++;
	for(int i=1;i<=n;i++)sze[gf(x[i])]++;
	int ans=1;
	for(int i=1;i<=tot;i++)if(f[i]==i)
	{
		if(szv[i]>sze[i])ans=1ll*ans*(power(2,szv[i])-1)%mod;
		else ans=1ll*ans*power(2,szv[i])%mod;
	}
	printendl(ans);
	return 0;
}