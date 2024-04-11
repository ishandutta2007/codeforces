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
int n,m,a[100111],t[111][100111],c[100111][111];
int main()
{
	for(int i=0;i<=100100;i++)
	{
		c[i][0]=1;
		for(int j=1;j<=101&&j<=i;j++)
		{
			c[i][j]=c[i-1][j]+c[i-1][j-1];
			if(c[i][j]>=mod)c[i][j]-=mod;
		}
	}
	get2(n,m);
	for(int i=1;i<=n;i++)get1(a[i]);
	for(int i=1;i<=m;i++)
	{
		int l,r,k;get3(l,r,k);
		t[k+1][l]++;if(t[k+1][l]>=mod)t[k+1][l]-=mod;
		for(int j=1;j<=k+1;j++)
		{
			t[j][r+1]-=c[r-l+1+k-j][k-j+1];
			if(t[j][r+1]<0)t[j][r+1]+=mod;
		}
	}
	for(int i=101;i>=1;i--)
	{
		for(int j=1;j<=n;j++)
		{
			t[i][j]+=t[i][j-1];
			if(t[i][j]>=mod)t[i][j]-=mod;
			t[i][j]+=t[i+1][j];
			if(t[i][j]>=mod)t[i][j]-=mod;
		}
	}
	for(int i=1;i<=n;i++)printf("%d ",(a[i]+t[1][i])%mod);
	return 0;
}