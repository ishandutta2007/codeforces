#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define lb(x) ((x)&(-x))
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define de(x) cout<<#x<<" x"<<endl
#define LCAFA rep(i,1,20)rep(j,1,n+1)fa[j][i]=fa[fa[j][i-1]][i-1]
#define all(x) x.begin(),x.end()
#define ls(x) x<<1
#define rs(x) x<<1|1
using namespace std;
const int N=3e3+9;
const ll mod=998244353;
ll dp[N][N];
ll jie2[N];
char s[N],t[N];
int main(){
	jie2[0]=1;
	rep(i,1,N)jie2[i]=jie2[i-1]*2%mod;
	scanf("%s",s+1);
	scanf("%s",t+1);
	int n=strlen(s+1),m=strlen(t+1);
	rep(i,1,N)dp[i][i-1]=1;
	ll ans=0;
	rep(len,1,n+1){
		rep(L,1,m+1){
			int R=L+len-1;
			if(R>m)break;
			if(t[L]==s[len])dp[L][R]+=dp[L+1][R];
			if(t[R]==s[len])dp[L][R]+=dp[L][R-1];
			dp[L][R]%=mod; 
		}
	//	cout<<len<<' '<<dp[1][m]<<"dp\n";
		per(i,2,len){
			int L=m-i+1;
			if(L<=0)continue;
			if(t[L]==s[len]){
				dp[L][m]+=dp[L+1][m];
			}
			dp[L][m]%=mod;
		}
		if(t[m]==s[len]&&len!=1){
			dp[m][m]=(jie2[len-1]+dp[m][m])%mod;
		}
	//	cout<<dp[2][2]<<' '<<dp[1][m]<<"  DP\n";
		ans=(ans+dp[1][m]*(n-len+1))%mod;
		dp[1][m]=0;
	}
	printf("%lld",ans);
}