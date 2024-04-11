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
const LL Linf=1000000000000ll;
const double pi=acos(-1.0);

int n,m,k;
LL pre[1000111],pre2[1000111];
vector<pii>in[100111],out[100111];
int main()
{
	get3(n,m,k);
	for(int i=1,d,f,t,c;i<=m;i++)
	{
		get2(d,f);get2(t,c);
		if(f==0)out[t].pb(mp(d,c));
		else in[f].pb(mp(d,c));
	}
	for(int i=1;i<=n;i++)
	{
//		printf("i= %d\n",i);
		in[i].pb(mp(1000001,0));
		out[i].pb(mp(0,0));
		sort(in[i].begin(),in[i].end());
		sort(out[i].begin(),out[i].end());reverse(out[i].begin(),out[i].end());
		LL mn=Linf;
		for(int j=0;j<(int)in[i].size();j++)
		{
			if(j==0)pre[1]+=mn;else pre[in[i][j-1].ff]+=mn;
			pre[in[i][j].ff]-=mn;
			mn=min(mn,1ll*in[i][j].ss);
		}
		mn=Linf;
		for(int j=0;j<(int)out[i].size();j++)
		{
			if(j)pre2[out[i][j-1].ff+1]-=mn;
			pre2[out[i][j].ff+1]+=mn;
			mn=min(mn,1ll*out[i][j].ss);
		}
	}
	for(int i=1;i<=1000000;i++)
	{
		pre[i]+=pre[i-1];
		pre2[i]+=pre2[i-1];
	}
	LL ans=Linf;
	for(int i=1;i<=1000000-k-1;i++)
		ans=min(ans,pre[i]+pre2[i+k+1]);
	if(ans==Linf)ans=-1;
	printendl(ans);
	return 0;
}