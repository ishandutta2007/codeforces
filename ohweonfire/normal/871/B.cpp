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

int n,ans[5555][2],pm[5555],final[5555],p[5555],v[5555];

void getans(int x,int y,int&v)
{
	printf("? %d %d\n",x,y);fflush(stdout);
	get1(v);
}
bool used[9999];
bool check(int x)
{
	memset(used,0,sizeof(used));
	for(int i=0;i<n;i++)used[v[i]^v[x]]=1;
	for(int i=0;i<n;i++)if(!used[i])return false;return true;
}
int b[5555];
bool check2(int x)
{
	memset(p,-1,sizeof(p));
	for(int i=0;i<n;i++){b[i]=v[i]^v[x];p[b[i]]=i;}
	for(int i=0;i<n;i++)if(p[i]==-1)return false;
	for(int i=0;i<n-1;i++)
	{
		if((p[i]^b[i])!=ans[i][0])return false;
		if((p[i]^b[i+1])!=ans[i][1])return false;
	}
	if((p[n-1]^b[n-1])!=ans[n-1][0])return false;
	return true;
}
int main()
{
	get1(n);
	if(n==1)
	{
		puts("!\n1\n0\n");fflush(stdout);
		return 0;
	}
	for(int i=0;i<n-1;i++)
	{
		getans(i,i,ans[i][0]);
		getans(i,i+1,ans[i][1]);
		v[i+1]=v[i]^ans[i][0]^ans[i][1];
	}
	getans(n-1,n-1,ans[n-1][0]);
	int cnt=0;
	for(int i=0;i<n;i++)if(check(i)&&check2(i))
	{
		cnt++;
		memcpy(final,p,sizeof(p));
	}
	printf("!\n%d\n",cnt);
	for(int i=0;i<n;i++)printf("%d ",final[i]);puts("");fflush(stdout);
	return 0;
}