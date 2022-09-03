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

char s[30],tt[30];
int t[500],a,ord[2][26];
int main()
{
	scanf("%s",s);
	memset(t,-1,sizeof(t));
	int st=0;
	for(int i=0,cur=0;i<27;i++)
	{
		if(t[s[i]]>=0){a=i-t[s[i]];st=t[s[i]];}
		else t[s[i]]=i;
	}
	int cur=0;
	for(int i=st;i<27;i++)
	{
		if(s[st]==s[i]&&i!=st)continue;
		tt[cur++]=s[i];
	}
	for(int i=0;i<st;i++)
	{
		if(s[st]==s[i]&&i!=st)continue;
		tt[cur++]=s[i];
	}
	if(a==1){puts("Impossible");return 0;}
	if(a%2==0)
	{
		int b=a/2-1,k=0;
		for(int i=b;i>=0;i--)ord[0][i]=k++;
		for(int i=0;i<13;i++)ord[1][i]=k++;
		for(int i=12;i>b;i--)ord[0][i]=k++;
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<13;j++)
			{
				putchar(tt[ord[i][j]]);
			}
			puts("");
		}
	}
	else
	{
		int b=a/2,k=0;
		for(int i=b;i>=0;i--)ord[0][i]=k++;
		for(int i=0;i<b;i++)ord[1][i]=k++;
		ord[1][b]=k++;
		for(int i=b+1;i<13;i++)ord[1][i]=k++;
		for(int i=12;i>b;i--)ord[0][i]=k++;
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<13;j++)
			{
				putchar(tt[ord[i][j]]);
			}
			puts("");
		}
	}
	return 0;
}