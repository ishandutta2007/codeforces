/*

DP





ll int
 dp 










*/
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
int n,dp[2][27][27],a[100005];
int mini[2][27][27];
char c[100005];
void solve(){
	scanf("%s",c+1);
	n=strlen(c+1);
	FOR(i,1,n)a[i]=c[i]-'a';
	if(n==1){
		puts("0");RE;
	}
	int T=0;
	rep(i,0,26){
		rep(j,0,26)if(i!=j){
			dp[T][i][j]=(a[1]!=i);
			dp[T][i][j]+=(a[2]!=j);
		}
	}
	FOR(i,3,n){
		rep(j,0,26){
			int min1=1e9,min2=1e9;
			rep(k,0,26)if(k!=j){
				if(dp[T][k][j]<min1){
					min2=min1;
					min1=dp[T][k][j];
				}else if(dp[T][k][j]<min2){
					min2=dp[T][k][j];
				}
			}
			rep(k,0,26){
				if(dp[T][k][j]==min1){
					mini[T][j][k]=min2;
				}else mini[T][j][k]=min1;
			}
		}
		rep(now,0,26){
			rep(l1,0,26)if(now!=l1){
				dp[T^1][l1][now]=mini[T][l1][now]+(now!=a[i]);
			}
		}
		T^=1;
	}
	int ans=1e9;
	rep(i,0,26){
		rep(j,0,26)if(i!=j)gmin(ans,dp[T][i][j]);
	}
	printf("%d\n",ans);
}
signed main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int t;
	scanf("%d",&t);
	while(t--)solve();
	RE 0;
}