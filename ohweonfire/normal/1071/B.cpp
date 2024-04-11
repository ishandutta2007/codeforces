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

char s[2111][2111];

int n,k,dp[2111][2111],mark[2111][2111];

vector<pii> ans,nans;
void go()
{
	int ansv=26;
	nans.clear();
	for(auto&v:ans)
	{
		int x=v.ff,y=v.ss;
		if(x<n)
		{
			if(ansv>s[x+1][y]-'a')
			{
				ansv=s[x+1][y]-'a';
				nans.clear();
			}
			if(ansv==s[x+1][y]-'a')nans.pb(mp(x+1,y));
		}
		if(y<n)
		{
			if(ansv>s[x][y+1]-'a')
			{
				ansv=s[x][y+1]-'a';
				nans.clear();
			}
			if(ansv==s[x][y+1]-'a')nans.pb(mp(x,y+1));
		}
	}
	ans.clear();
	for(auto&v:nans)if(!mark[v.ff][v.ss])
	{
		mark[v.ff][v.ss]=1;
		ans.pb(v);
	}
	putchar(ansv+'a');
}

int main()
{
	get2(n,k);
	for(int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dp[i][j]=max(dp[i-1][j],dp[i][j-1])+(s[i][j]=='a');
	
	int ansl=-1;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
	{
		if(dp[i][j]+k>=i+j-1)
		{
			if(ansl<i+j-1)
			{
				ansl=i+j-1;
				ans.clear();
			}
			if(ansl==i+j-1)ans.pb(mp(i,j));
		}
	}
	if(ansl==-1)
	{
		putchar(s[1][1]);
		ansl=1;
		ans.pb(mp(1,1));
	}
	else for(int i=1;i<=ansl;i++)putchar('a');
	for(int i=ansl+1;i<n+n;i++)go();
	return 0;
}