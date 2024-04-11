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

const int mod=1e9+7;
const int rev[]={0,1,3,2,4,0};

struct coef
{
	int a[555];
	void clear()
	{
		memset(a,0,sizeof(a));
	}
};
coef operator *(coef a,int b)
{
	coef ret;ret.clear();
	for(int i=0;i<555;i++)ret.a[i]=a.a[i]*b%5;
	return ret;
}
coef operator +(coef a,coef b)
{
	coef ret;ret.clear();
	for(int i=0;i<555;i++)ret.a[i]=(a.a[i]+b.a[i])%5;
	return ret;
}
coef ans[555];
int n,m,q,a[555][555],b[555][555],t[555],num[555];
char s[555];

LL ttt;
bool check()
{
	memset(t,0,sizeof(t));
	for(int i=1;i<=n;i++)if(num[i])
	{
		for(int j=1;j<=m;j++)
			t[i]=(t[i]+ans[num[i]].a[j]*(s[j]-'a'))%5;
	}
	for(int i=1;i<=m;i++)
	{
		int cur=0;
		for(int j=1;j<=n;j++)cur=(cur+b[i][j]*t[j])%5;
		if(cur!=s[i]-'a')return false;
	}
	return true;
}
void gauss()
{
	for(int i=1;i<=m;i++)
	{
		ans[i].clear();
		ans[i].a[i]=1;
	}
	int cur=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=cur;j<=m;j++)
		{
			if(a[j][i])
			{
				for(int k=1;k<=n;k++)swap(a[cur][k],a[j][k]);
				swap(ans[cur],ans[j]);
				break;
			}
		}
		if(a[cur][i]==0)continue;
		num[i]=cur;
		int c=rev[a[cur][i]];
		for(int j=1;j<=n;j++)a[cur][j]=a[cur][j]*c%5;
		ans[cur]=ans[cur]*c;
		for(int j=1;j<=m;j++)
		{
			if(j==cur)continue;
			c=(5-a[j][i])%5;
			for(int k=1;k<=n;k++)a[j][k]=(a[j][k]+c*a[cur][k])%5;
			ans[j]=ans[j]+ans[cur]*c;
		}
		cur++;
	}
	ttt=1;
	while(cur<=n)
	{
		cur++;
		ttt=ttt*5%mod;
	}
}

int main()
{
	get2(n,m);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		for(int j=1;j<=m;j++)
			a[j][i]=s[j]-'a';
	}
	memcpy(b,a,sizeof(a));
	gauss();
	get1(q);
	for(int i=1;i<=q;i++)
	{
		scanf("%s",s+1);
		if(check())printendl(ttt);
		else puts("0");
	}
	return 0;
}