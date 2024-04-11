#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

#define ckmn(x,y) (x>(y)?x=(y):0)
char s[N],t[N];
int dp[N][N],nxt[N];

signed main()
{
	scanf("%s%s",s+1,t+1);
	int n=strlen(s+1),m=strlen(t+1);
	for (int i=1;i<=n;i++)
	{
		int now=0;
		for (int j=i;j<=n;j++)
		{
			now+=s[j]!='.'?1:-1;
			if (now<0) break;
			if (!now){nxt[i]=j;break;}
		}
	}
	memset(dp,0x3f,sizeof(dp));
	const int inf=dp[0][0];
	dp[0][0]=0;
	for (int i=0;i<=n;i++)
	for (int j=0;j<=m;j++)
	if (dp[i][j]<inf)
	{
		if (nxt[i+1]) ckmn(dp[nxt[i+1]][j],dp[i][j]);
		if (s[i+1]==t[j+1]) ckmn(dp[i+1][j+1],dp[i][j]);
		ckmn(dp[i+1][j],dp[i][j]+1);
	}
	print(dp[n][m]);
	
	return 0;
}