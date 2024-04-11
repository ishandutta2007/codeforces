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

#define getcode(i,j) (((i)>>(j))&1)
int n;
multiset<LL>st;
LL ans[100111];

bool getv(LL l,LL r){return st.lower_bound(l)!=st.lower_bound(r);}
int main()
{
	get1(n);
	for(int i=1;i<=n;i++)
	{
		LL a;get1(a);
		st.insert(a);
	}
	
	LL last=0;
	for(int i=1;i<=n;i++)
	{
		bool ok=0;
		for(int j=0;j<60;j++)if(!getcode(last,j))
		{
			if(getv(1ll<<j,1ll<<j+1))
			{
				LL cur=1ll<<j;
				for(int k=j-1;k>=0;k--)
				{
					LL tv=getcode(last,k);
					if(getv(cur|(tv<<k),(cur|(tv<<k))+(1ll<<k)))
						cur|=(tv<<k);
					else cur|=((tv^1)<<k);
				}
				ans[i]=cur;last^=cur;
				st.erase(st.find(cur));
				ok=1;break;
			}
		}
		if(!ok)
		{
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	for(int i=1;i<=n;i++)printf("%I64d ",ans[i]);
	return 0;
}