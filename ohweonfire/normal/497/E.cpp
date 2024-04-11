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
struct matrix
{
	int a[33][33];
	void clear(int x)
	{
		for(int i=0;i<33;i++)for(int j=0;j<33;j++)
			a[i][j]=x*(i==j);
	}
	void rev()
	{
		for(int i=0;i<33;i++)for(int j=0;j<33;j++)if(i!=j)a[i][j]=(mod-a[i][j])%mod;
	}
	int* operator [](const int x){return a[x];}
};
matrix v[65][33],pre[33],suf[33];
LL n;int k;
matrix operator *(matrix a,matrix b)
{
	matrix ret;ret.clear(0);
	for(int i=0;i<33;i++)for(int j=0;j<33;j++)for(int k=0;k<33;k++)
		ret[i][j]=(ret[i][j]+1ll*a[i][k]*b[k][j])%mod;
	return ret;
}

matrix calc(LL x,int st)
{
	matrix ret;ret.clear(1);
	if(x==0)return ret;
	LL prod=1;int lg=0;
	while(prod<=x/k)
	{
		lg++;
		prod*=k;
	}
	int tmp=x/prod;
	for(int i=0;i<tmp;i++)ret=ret*v[lg][(st+i)%k];
	ret=ret*calc(x-tmp*prod,(st+tmp)%k);
	return ret;
}
int main()
{
	get2(n,k);
	int lg=0;LL prod=1;
	while(prod<=n/k)
	{
		lg++;
		prod*=k;
	}
	for(int _=0;_<k;_++)
	{
		for(int i=0;i<=k;i++)for(int j=0;j<=k;j++)
			if(i==j||i==_)v[0][_][i][j]=1;
			else v[0][_][i][j]=0;
	}
	for(int _=1;_<=lg;_++)
	{
		pre[0].clear(1);
		for(int i=0;i<k;i++)pre[i+1]=pre[i]*v[_-1][i];
		suf[k].clear(1);
		for(int i=k-1;i>=0;i--)suf[i]=v[_-1][i]*suf[i+1];
		for(int i=0;i<k;i++)v[_][i]=suf[i]*pre[i];
	}
	matrix tran=calc(n,0);
	int ans=0;for(int i=0;i<=k;i++)ans=(ans+tran[i][k])%mod;
	printendl(ans);
	return 0;
}