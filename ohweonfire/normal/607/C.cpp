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

const uLL base=53;
uLL power[2000111],hs[2000111];
int n,a[2000111],val[256];
uLL calhash(int x,int y){return power[2000110-x]*(hs[y]-hs[x-1]);}
char s[1000111],t[1000111];

int main()
{
	power[0]=1;for(int i=1;i<2000111;i++)power[i]=power[i-1]*base;
	val['N']=0;val['S']=1;val['E']=2;val['W']=3;
	
	get1(n);n--;scanf("%s%s",s+1,t+1);
	for(int i=1;i<=n;i++)a[i]=val[s[n+1-i]];
	for(int i=1;i<=n;i++)a[i+n]=val[t[i]]^1;
	for(int i=1;i<=n+n;i++)hs[i]=hs[i-1]+power[i]*a[i];
	
//	for(int i=1;i<=n+n;i++)printf("%d ",a[i]);puts("");
	
	for(int i=1;i<=n;i++)
	{
		if(calhash(1,i)==calhash(n+n-i+1,n+n))
		{
//			printf("%d %d\n",1,i);
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}