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

char s[200111];
int n,t,add,pt;
void inc(int p)
{
	int c=1;
	for(int i=p-1;i>pt;i--)
	{
		s[i]+=c;
		c=(s[i]-'0')/10;s[i]=(s[i]-'0')%10+'0';
		if(c==0)break;
	}
	for(int i=p;i<=n;i++)s[i]=0;n=p-1;
	add+=c;
}
int main()
{
	get2(n,t);scanf("%s",s+1);
	pt=1;while(s[pt]!='.')pt++;
	int fir=pt+1;while(fir<=n&&s[fir]<'5')fir++;
	if(fir==n+1)
	{
		printf("%s\n",s+1);
		return 0;
	}
	for(;fir>pt&&t;fir--,t--)
	{
		if(s[fir]<'5')break;
		inc(fir);
	}
	for(int i=pt-1;i>=1;i--)
	{
		s[i]+=add;
		add=(s[i]-'0')/10;s[i]=(s[i]-'0')%10+'0';
	}
	if(add)putchar('1');for(int i=1;i<pt;i++)putchar(s[i]);
	while(s[n]=='0')s[n--]=0;
	if(n>pt)printf("%s\n",s+pt);
	return 0;
}