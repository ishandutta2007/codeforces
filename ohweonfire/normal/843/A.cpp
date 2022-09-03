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

int n,a[100111],b[100111];
bool use[100111];
vector<vector<int> >v;
int main()
{
	get1(n);for(int i=1;i<=n;i++)get1(a[i]);
	memcpy(b,a,sizeof(a));sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)a[i]=lower_bound(b+1,b+n+1,a[i])-b;
	for(int i=1;i<=n;i++)
	{
		if(use[i])continue;
		vector<int>cur;
		int tmp=i;
		while(!use[tmp])
		{
			cur.pb(tmp);
			use[tmp]=1;
			tmp=a[tmp];
		}
		v.pb(cur);
	}
	printf("%d\n",(int)v.size());
	for(int i=0;i<(int)v.size();i++)
	{
		printf("%d ",(int)v[i].size());
		sort(v[i].begin(),v[i].end());
		for(int j=0;j<(int)v[i].size();j++)
			printf("%d ",v[i][j]);
		puts("");
	}
	return 0;
}