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
#include<unordered_map>
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

unordered_map<LL,int> cnt;
int n;
LL add=10000000000ll,pw10[20];
vector<LL> vs[70111][11];
char s[70111][11];
int main()
{
	pw10[0]=1;for(int i=1;i<20;i++)pw10[i]=pw10[i-1]*10;
	get1(n);
	for(int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=9;j++)
		{
			LL sum=0;
			for(int k=j;k<=9;k++)
			{
				sum=sum*10+s[i][k]-'0';
				vs[i][k-j+1].pb(sum+pw10[k-j+1]*add);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int l=1;l<=9;l++)
		{
			sort(vs[i][l].begin(),vs[i][l].end());
			for(int j=0;j<(int)vs[i][l].size();j++)
				if(j==0||vs[i][l][j]!=vs[i][l][j-1])cnt[vs[i][l][j]]++;
		}
	}
	char dig[20];
	for(int i=1;i<=n;i++)
	{
		for(int l=1;l<=9;l++)
		{
			bool ok=0;
			for(int j=0;j<(int)vs[i][l].size();j++)
				if(cnt[vs[i][l][j]]==1)
				{
					sprintf(dig,"%I64d\n",vs[i][l][j]-pw10[l]*add);int len=strlen(dig);
					while(len<=l){len++;putchar('0');}printf("%I64d\n",vs[i][l][j]-pw10[l]*add);
					ok=1;
					break;
				}
			if(ok)break;
		}
	}
	return 0;
}