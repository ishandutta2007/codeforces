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

char s[100];
int n,dp[80][80][80][2],ans,cnt[80][3];// V  K  X
vector<int> all[3];

void trynext(int v,int k,int x,int val,char nxt)
{
	if(v+k+x==n)
	{
		ans=min(ans,val);
		return;
	}
	if(v+(nxt=='V')>cnt[n][0]||k+(nxt=='K')>cnt[n][1]||x+(nxt=='X')>cnt[n][2])return;
	int &t=dp[v+(nxt=='V')][k+(nxt=='K')][x+(nxt=='X')][nxt=='V'],pos;
	if(nxt=='V')pos=all[0][v];else if(nxt=='K')pos=all[1][k];else pos=all[2][x];
	t=min(t,val+pos-v-k-x-1+max(0,cnt[pos-1][0]-v)+max(0,cnt[pos-1][1]-k)+max(0,cnt[pos-1][2]-x));
//	printf("%d %d %d %d %c\n",v,k,x,val,nxt);
}
int main()
{
	for(int i=0;i<80;i++)for(int j=0;j<80;j++)for(int k=0;k<80;k++)dp[i][j][k][0]=dp[i][j][k][1]=inf;
	
	get1(n);scanf("%s",s+1);
	for(int i=1;i<=n;i++)
	{
		memcpy(cnt[i],cnt[i-1],sizeof(cnt[i]));
		if(s[i]=='V')
		{
			cnt[i][0]++;
			all[0].pb(i);
		}
		else if(s[i]=='K')
		{
			cnt[i][1]++;
			all[1].pb(i);
		}
		else
		{
			cnt[i][2]++;
			all[2].pb(i);
		}
	}
	dp[0][0][0][0]=0;ans=inf;
	for(int i=0;i<=cnt[n][0];i++)
		for(int j=0;j<=cnt[n][1];j++)
			for(int k=0;k<=cnt[n][2];k++)
			{
				if(dp[i][j][k][0]<inf)
				{
					trynext(i,j,k,dp[i][j][k][0],'V');
					trynext(i,j,k,dp[i][j][k][0],'K');
					trynext(i,j,k,dp[i][j][k][0],'X');
				}
				if(dp[i][j][k][1]<inf)
				{
					trynext(i,j,k,dp[i][j][k][1],'V');
					trynext(i,j,k,dp[i][j][k][1],'X');
				}
			}
	printendl(ans);
	return 0;
}