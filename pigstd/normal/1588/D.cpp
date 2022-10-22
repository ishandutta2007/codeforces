#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define WT int TT=read();while(TT--) 
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int inf=1e18;
const int M=60;
const int N=(1<<10)+10;
int n,a[M][M<<1],t1[15][M],t2[15][M],vis[M][N],dp[M][N];
pair<int,int>pre[M][N];

int F(char ch)
{
	if (ch<='z'&&ch>='a')return ch-'a'+1;
	return ch-'A'+27;
}

int check(int c,int x)
{
	int f=1;
	for (int i=1;i<=n;i++)
		if ((x>>(i-1))&1)f&=t2[i][c]?1:0; 
		else f&=(t1[i][c]?1:0);
	return f;
}

int dfs(int c,int x)
{
	if (vis[c][x])return dp[c][x];
	if (!check(c,x))return vis[c][x]=1,-inf;
	vis[c][x]=dp[c][x]=1;
	for (int i=1;i<=52;i++)
	{
		int s=0,f=1;
		for (int j=1;j<=n;j++)
		{
			int p=((x>>(j-1))&1)?t2[j][c]:t1[j][c];
			if (t2[j][i]!=0&&t2[j][i]<p)s^=1<<(j-1);
			else if (t1[j][i]==0||t1[j][i]>=p)f=0;
		}
		if (!f)continue;
		if (dfs(i,s)+1>dp[c][x])dp[c][x]=dfs(i,s)+1,pre[c][x]=mp(i,s);
	}return dp[c][x];
}

void solve()
{
	n=read();
	for (int i=1;i<=n;i++)
	{
		string s;cin>>s;
		for (int j=0;j<s.size();j++)
		{
			a[i][j+1]=F(s[j]);
			if (t1[i][F(s[j])])t2[i][F(s[j])]=j+1;
			else t1[i][F(s[j])]=j+1;
		}
	}
//	cout<<dfs(26,0)<<endl;
	int res=0,maxp1=0,maxp2=0;
	for (int i=1;i<=52;i++)
		for (int j=0;j<(1<<n);j++)
			if (dfs(i,j)>res)res=dfs(i,j),maxp1=i,maxp2=j;
	cout<<res<<endl;vector<int>ans;
	while(maxp1!=0)
	{
		ans.pb(maxp1);
		auto x=pre[maxp1][maxp2];
		maxp1=x.x,maxp2=x.y;
	}int sz=ans.size();
	for (int i=sz-1;i>=0;i--)
		if (ans[i]<=26)cout<<(char)(ans[i]+'a'-1);
		else cout<<(char)(ans[i]+'A'-27);
	puts("");
	memset(t1,0,sizeof(t1));
	memset(t2,0,sizeof(t2));
	memset(vis,0,sizeof(vis));
	memset(pre,0,sizeof(pre));
	memset(dp,0,sizeof(dp));
}

signed main()
{
	WT solve();
	return 0;
}
/*
1
3
azAZ
aAzZ
aazz
*/