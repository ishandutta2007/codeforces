//  This code is written by Eric Sunli Chen ( OhWeOnFire ).
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <map>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;
template<typename T>
void get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'; t=getchar());
	if(t=='-')neg=true,t=getchar();
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;
}
template<typename T>
void print_int(T x)
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

bool dp[505][505][505];
int n,t,c[505];
int main()
{
	dp[0][0][0]=1;
	get2(n,t);
	for(int i=0;i<n;i++)get1(c[i]);
	for(int i=0;i<n;i++)
		for(int j=0;j<=t;j++)
			for(int k=0;k<=j;k++)
				if(dp[i][j][k])
				{
					dp[i+1][j][k]=1;
					if(j+c[i]<=t)
					{
						dp[i+1][j+c[i]][k]=1;
						dp[i+1][j+c[i]][k+c[i]]=1;
					}
				}
	int cnt=0;
	for(int i=0;i<=t;i++)if(dp[n][t][i])cnt++;
	printf("%d\n",cnt);
	for(int i=0;i<=t;i++)if(dp[n][t][i])printf("%d ",i);
	return 0;
}