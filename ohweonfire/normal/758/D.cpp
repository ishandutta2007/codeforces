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

char s[100];
LL conv(int x,int y)
{
	LL ret=0;
	for(int i=y;i>=x;i--)ret=ret*10+s[i]-'0';
	return ret;
}
int n,m;
int main()
{
	scanf("%d%s",&n,s+1);
	m=strlen(s+1);
	reverse(s+1,s+m+1);
	LL ans=0,p=1;
	int cur=0;
	while(cur!=m)
	{
		LL last=-1,tmp;
		int lj;
		for(int j=cur+1;j<=m&&j<=cur+10;j++)
		{
			if((tmp=conv(cur+1,j))>=n)break;
			if(j==cur+1||s[j]!='0')
			{
				last=tmp;
				lj=j;
			}
		}
		ans+=last*p;
		cur=lj;
//		printf("p= %d\n",cur);
		p*=n;
	}
	printf("%I64d\n",ans);
	return 0;
}