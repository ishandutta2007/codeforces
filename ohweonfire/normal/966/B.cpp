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

int n,x1,x2,c[300111],ord[300111];

int v1[300111],v2[300111];
LL eval(int l,int r){return 1ll*c[ord[l]]*(r-l+1);}

bool cmp(int x,int y){return c[x]<c[y];}
int main()
{
	get3(n,x1,x2);
	for(int i=1;i<=n;i++)
	{
		get1(c[i]);
		ord[i]=i;
	}
	sort(ord+1,ord+n+1,cmp);
	int mn1=inf,mn2=inf;
	for(int i=1;i<=n;i++)
	{
		mn1=min(mn1,i+(x1-1)/c[ord[i]]);
		mn2=min(mn2,i+(x2-1)/c[ord[i]]);
		if(eval(i,n)>=x1&&mn2<i)
		{
			puts("Yes");
			int j;
			for(j=1;j<i;j++)if(eval(j,i-1)>=x2)break;
			printf("%d %d\n",n+1-i,i-j);
			for(int k=i;k<=n;k++)printf("%d ",ord[k]);puts("");
			for(int k=j;k<i;k++)printf("%d ",ord[k]);
			return 0;
		}
		if(eval(i,n)>=x2&&mn1<i)
		{
			puts("Yes");
			int j;
			for(j=1;j<i;j++)if(eval(j,i-1)>=x1)break;
			printf("%d %d\n",i-j,n+1-i);
			for(int k=j;k<i;k++)printf("%d ",ord[k]);puts("");
			for(int k=i;k<=n;k++)printf("%d ",ord[k]);
			return 0;
		}
	}
	puts("No");
	return 0;
}