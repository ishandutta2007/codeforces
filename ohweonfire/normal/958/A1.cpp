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

int n;
char s[15][15],t[15][15],tmp[15][15];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++)scanf("%s",t[i]+1);
	
	for(int t1=0;t1<2;t1++)
	{
		for(int t2=0;t2<2;t2++)
		{
			for(int t3=0;t3<4;t3++)
			{
				bool ok=1;
				for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)ok&=(s[i][j]==t[i][j]);
				if(ok)
				{
					puts("Yes");
					return 0;
				}
				for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)tmp[j][n-i+1]=s[i][j];
				memcpy(s,tmp,sizeof(s));
			}
			for(int i=1;i<=n;i++)for(int j=1;j<=(n+1)>>1;j++)swap(s[i][j],s[i][n-j+1]);
		}
		for(int i=1;i<=(n+1)>>1;i++)for(int j=1;j<=n;j++)swap(s[i][j],s[n-i+1][j]);
	}
	puts("No");
	return 0;
}