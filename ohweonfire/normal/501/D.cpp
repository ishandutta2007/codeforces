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

int a[200111],b[200111],n,s[200111],c[200111];
int bit[200111];
void add(int x,int y=1){for(;x<=n;x+=x&-x)bit[x]+=y;}
int query(int x){int ret=0;for(;x;x-=x&-x)ret+=bit[x];return ret;}
int getrk(int x)
{
	int l=0,r=n,mid;
	while(l<r-1)
	{
		mid=(l+r)>>1;
		if(query(mid)<x)l=mid;
		else r=mid;
	}
	return r;
}
void getord(int*a)
{
	memset(bit,0,sizeof(bit));
	for(int i=1;i<=n;i++)add(i);
	for(int i=1;i<=n;i++)
	{
		add(a[i],-1);
		s[i]+=query(a[i]);
	}
}
int main()
{
	get1(n);
	for(int i=1;i<=n;i++){get1(a[i]);a[i]++;}
	for(int i=1;i<=n;i++){get1(b[i]);b[i]++;}
	getord(a);getord(b);
	for(int i=n;i>=1;i--)
	{
		if(i>1)s[i-1]+=s[i]/(n-i+1);
		s[i]%=(n-i+1);
	}
	
	memset(bit,0,sizeof(bit));for(int i=1;i<=n;i++)add(i);
	for(int i=1;i<=n;i++)
	{
		int t=getrk(s[i]+1);
		printf("%d ",t-1);
		add(t,-1);
	}
	return 0;
}