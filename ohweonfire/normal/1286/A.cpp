// This amazing code is by Eric Sunli Chen.
#include<bits/stdc++.h>
using namespace std;
template<typename T> bool get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'&&t!=EOF; t=getchar());
	if(t=='-')neg=true,t=getchar();if(t==EOF)return false;
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;return true;
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
#define get2(a,b) (get1(a)&&get1(b))
#define get3(a,b,c) (get1(a)&&get2(b,c))
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
typedef vector<int> vi;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

const int maxn=111;
int n,p[maxn];

int dp[maxn][maxn][maxn][2];

int main()
{
	get1(n);
	int c[2]={n/2,n-n/2};
	for(int i=1;i<=n;i++)
	{
		get1(p[i]);
		if(p[i])c[p[i]%2]--;
	}
	
	memset(dp,inf,sizeof(dp));
	dp[1][0][0][0]=0;dp[1][0][0][1]=0;
	for(int i=1;i<=n;i++)for(int j=0;j<=c[0];j++)for(int k=0;k<=c[1];k++)for(int last=0;last<2;last++)if(dp[i][j][k][last]!=inf)
	{
		if(p[i]==0||p[i]%2==0)dp[i+1][j+(p[i]==0)][k][0]=min(dp[i+1][j+(p[i]==0)][k][0],dp[i][j][k][last]+last);
		if(p[i]==0||p[i]%2==1)dp[i+1][j][k+(p[i]==0)][1]=min(dp[i+1][j][k+(p[i]==0)][1],dp[i][j][k][last]+1-last);
	}
	printf("%d\n",min(dp[n+1][c[0]][c[1]][0],dp[n+1][c[0]][c[1]][1]));
	return 0;
}