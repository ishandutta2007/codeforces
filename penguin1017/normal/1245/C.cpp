#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define per(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define ll long long
using namespace std;
const int N=1e5+9;
const ll mod=1e9+7;
char s[N];
ll dp[N][2];
int main()
{
	scanf("%s",s+1);
	int len=strlen(s+1);
	rep(i,1,len+1){
		if(s[i]=='w'||s[i]=='m'){
			printf("0");
			return 0;
		}
	}
	dp[1][0]=1;
	rep(i,2,len+1){
		dp[i][0]=dp[i-1][0]+dp[i-1][1];
		if(dp[i][0]>=mod)dp[i][0]-=mod;
		if(s[i]=='u'&&s[i-1]=='u')dp[i][1]=dp[i-1][0];
		if(s[i]=='n'&&s[i-1]=='n')dp[i][1]=dp[i-1][0];
	}
	ll ans=dp[len][1]+dp[len][0];
	ans%=mod;
	printf("%lld",ans);
}