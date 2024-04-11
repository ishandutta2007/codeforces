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

char s[100111],t[100111];
int spre[100111],tpre[100111],slen[100111],tlen[100111],n,m,q,ans[100111];
int main()
{
	scanf("%s%s",s+1,t+1);n=strlen(s+1);m=strlen(t+1);
	for(int i=1;i<=n;i++)
	{
		spre[i]=spre[i-1]+(s[i]!='A');
		slen[i]=(s[i]!='A'?0:slen[i-1]+1);
	}
	for(int i=1;i<=m;i++)
	{
		tpre[i]=tpre[i-1]+(t[i]!='A');
		tlen[i]=(t[i]!='A'?0:tlen[i-1]+1);
	}
	get1(q);
	for(int i=1,sl,sr,tl,tr,sa,sb,ta,tb;i<=q;i++)
	{
		get2(sl,sr);get2(tl,tr);
		sa=spre[sr]-spre[sl-1];sb=min(slen[sr],sr-sl+1);
		ta=tpre[tr]-tpre[tl-1];tb=min(tlen[tr],tr-tl+1);
		if(sa<=ta&&(ta-sa)%2==0&&sb>=tb&&((sb-tb)%3==0||sa<ta))ans[i]=1;
		if(!sa&&ta&&sb==tb)ans[i]=0;
	}
	for(int i=1;i<=q;i++)putchar(ans[i]+'0');
	return 0;
}