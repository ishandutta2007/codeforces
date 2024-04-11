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

#define code(i,j) (((i)>>(j))&1)
int n,a[111],b[111];
char s[111];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%s",s);
		if(s[0]=='R')a[i]=0;else if(s[0]=='G')a[i]=1;else if(s[0]=='B')a[i]=2;else if(s[0]=='Y')a[i]=3;else a[i]=4;
		b[i]=s[1]-'1';
	}
	int ans=inf;
	for(int i=0;i<(1<<10);i++)
	{
		bool ok=1;
		for(int j=0;j<n;j++)for(int k=j+1;k<n;k++)
		{
			if(a[j]!=a[k]&&b[j]==b[k]&&!code(i,a[j])&&!code(i,a[k]))ok=0;
			if(b[j]!=b[k]&&a[j]==a[k]&&!code(i,b[j]+5)&&!code(i,b[k]+5))ok=0;
			if(a[j]!=a[k]&&b[j]!=b[k]&&!code(i,a[j])&&!code(i,a[k])&&!code(i,b[j]+5)&&!code(i,b[k]+5))ok=0;
		}
		if(ok)ans=min(ans,__builtin_popcount(i));
	}
	printendl(ans);
	return 0;
}