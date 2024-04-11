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

int n,a[100111],have[100111],dpl[100111],dpr[100111],ans[100111];

int bit[100111];
void maxi(int x,int v){for(;x<100111;x+=x&-x)bit[x]=max(bit[x],v);}
int query(int x){int ret=0;for(;x;x-=x&-x)ret=max(ret,bit[x]);return ret;}

vector<int> vs;
int main()
{
	get1(n);
	for(int i=1;i<=n;i++)
	{
		get1(a[i]);
		vs.pb(a[i]);
	}
	sort(vs.begin(),vs.end());
	vs.erase(unique(vs.begin(),vs.end()),vs.end());
	for(int i=1;i<=n;i++)a[i]=upper_bound(vs.begin(),vs.end(),a[i])-vs.begin();
	for(int i=1;i<=n;i++)
	{
		dpl[i]=query(a[i]-1)+1;
		maxi(a[i],dpl[i]);
	}
	memset(bit,0,sizeof(bit));
	for(int i=n;i>=1;i--)
	{
		dpr[i]=query(n-a[i])+1;
		maxi(n-a[i]+1,dpr[i]);
	}
	int tans=query(n);
	for(int i=1;i<=n;i++)
	{
		ans[i]=1;
		if(dpl[i]+dpr[i]-1==tans)
		{
			ans[i]=2;
			if(have[dpl[i]])have[dpl[i]]=-1;
			else have[dpl[i]]=i;
		}
	}
	for(int i=1;i<=n;i++)if(have[i]>0)ans[have[i]]=3;
	for(int i=1;i<=n;i++)printf("%d",ans[i]);
	return 0;
}