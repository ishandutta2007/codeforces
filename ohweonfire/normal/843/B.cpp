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

int n,st,x,tt[50111];
int main()
{
	srand((unsigned int)time(NULL));
	get3(n,st,x);
	
	for(int i=1;i<=n;i++)tt[i]=i;random_shuffle(tt+1,tt+n+1);
	int cur=st,cv=-1;
	for(int i=1,t,v,nxt;i<=min(n,1000);i++)
	{
		t=tt[i];printf("? %d\n",t);fflush(stdout);
		get2(v,nxt);if(v<x&&(cv==-1||cv<v)){cur=nxt;cv=v;}
	}
	for(int i=1,v;i<1000;i++)
	{
		if(cur==-1)
		{
			puts("! -1");fflush(stdout);
			return 0;
		}
		printf("? %d\n",cur);fflush(stdout);
		get2(v,cur);
		if(v>=x)
		{
			printf("! %d\n",v);fflush(stdout);
			return 0;
		}
	}
	for(;;);
	return 0;
}