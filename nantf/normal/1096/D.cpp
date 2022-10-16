#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=100010;
const char hard[6]="*hard";
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	char ch=getchar();int x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,a[maxn];
char str[maxn];
ll dp[maxn][4];
int main(){
	n=read();
	scanf("%s",str+1);
	FOR(i,1,n) a[i]=read();
	MEM(dp,0x3f);
	FOR(j,0,3) dp[0][j]=0;
	FOR(i,1,n) FOR(j,0,3){
		if(str[i]!=hard[j+1]) dp[i][j]=min(dp[i][j],dp[i-1][j]);
		else{
			dp[i][j]=min(dp[i][j],dp[i-1][j]+a[i]);
			if(j) dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
		}
	}
	ll ans=LLONG_MAX;
	FOR(j,0,3) ans=min(ans,dp[n][j]);
	printf("%lld\n",ans);
}