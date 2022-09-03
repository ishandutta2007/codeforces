// inthis amazing code is by Eric Sunli Chen.
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
void get_int(int &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'; t=getchar());
	if(t=='-')neg=true,t=getchar();
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;
}
void print_int(int x)
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


const int mod=1e9+7;
int pre[1000111][22];
int q,r,n,mn[1000111];
void prework()
{
	pre[0][0]=1;
	for(int i=1;i<=20;i++)
		pre[0][i]=pre[0][i-1]+2;
	for(int i=1;i<=1000000;i++)
		for(int j=0;j<=20;j++)
		{
			pre[i][j]=pre[i-1][j];
			if(j)pre[i][j]+=pre[i][j-1];
			if(pre[i][j]>=mod)pre[i][j]-=mod;
		}
	for(int i=2;i<=1000000;i++)
	{
		if(mn[i])continue;
		for(int j=i;j<=1000000;j+=i)
			mn[j]=i;
	}
}
int main()
{
	prework();
	get1(q);
	for(int i=1,n,r;i<=q;i++)
	{
		get2(r,n);
		int ans=1;
		while(mn[n])
		{
			int cnt=0,tmp=mn[n];
			while(n%tmp==0)
			{
				n/=tmp;
				cnt++;
			}
			ans=1ll*ans*(pre[r][cnt]+mod-pre[r][cnt-1])%mod;
		}
		printendl(ans);
	}
	return 0;
}