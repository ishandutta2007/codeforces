#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e3+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int t1[N][26],t2[N][26],dp[N][N];
char s[N],t[N];
void work()
{
	int n=read();
	scanf("%s%s",s+1,t+1);
	for (int i=1;i<=n;i++)
	{
		memcpy(t1[i],t1[i-1],sizeof(t1[i]));
		memcpy(t2[i],t2[i-1],sizeof(t2[i]));
		t1[i][s[i]-'a']++,t2[i][t[i]-'a']++;
	}
	for (int i=0;i<26;i++) if (t1[n][i]!=t2[n][i]) return puts("-1"),void();
	for (int i=1;i<=n;i++)
	for (int j=0;j<=n;j++) dp[i][j]=N;
	for (int i=0;i<=n;i++) dp[0][i]=0;
	for (int i=1;i<=n;i++)
	for (int j=i;j<=n;j++)
	{
		dp[i][j]=dp[i-1][j]+1;
		if (s[i]==t[j]) dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
		if (t1[i][t[j]-'a']<t2[j][t[j]-'a']) dp[i][j]=min(dp[i][j],dp[i][j-1]);
	}
	print(dp[n][n]);
}
signed main()
{
	int T=read();
	while (T--) work(); 
	
	return 0;
}