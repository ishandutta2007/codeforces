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
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

#define right hehe
const int maxn=2111;
const int mod=1e9+7;
inline void add(int&x,int y){x+=y;if(x>=mod)x-=mod;}
int n,m,row[maxn][maxn],col[maxn][maxn],down[maxn][maxn],right[maxn][maxn];
char s[maxn][maxn];
int main()
{
	get2(n,m);
	if(n==1&&m==1)
	{
		puts("1");
		return 0;
	}
	for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
	for(int i=n;i>=1;i--)for(int j=m;j>=1;j--)
	{
		row[i][j]=row[i][j+1];
		col[i][j]=col[i+1][j];
		if(s[i][j]=='R')
		{
			row[i][j]++;
			col[i][j]++;
		}
	}
	
	down[1][1]=right[1][1]=1;down[1][2]=mod-1;right[2][1]=mod-1;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
	{
		add(down[i][j],down[i][j-1]);
		add(right[i][j],right[i-1][j]);
		
		add(right[i+1][j],down[i][j]);
		add(right[n-col[i+1][j]+1][j],mod-down[i][j]);
		
		add(down[i][j+1],right[i][j]);
		add(down[i][m-row[i][j+1]+1],mod-right[i][j]);
//		for(int k=i+1;k<=n-col[i+1][j];k++)add(right[k][j],down[i][j]);
//		for(int k=j+1;k<=m-row[i][j+1];k++)add(down[i][k],right[i][j]);
	}
	
	int ans=down[n][m]+right[n][m];if(ans>=mod)ans-=mod;
	printendl(ans);
	return 0;
}