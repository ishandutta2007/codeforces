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
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)^1)
using namespace std;
int dp[5005][5005];
int n,m;
char s[5005],c[5005];
int ti,td,tr,te,nxt[5005][26],nxt2[5005][26];
signed main(){
	scanf("%d%d%d%d",&ti,&td,&tr,&te);
	scanf("%s",s+1);n=strlen(s+1);
	scanf("%s",c+1);m=strlen(c+1);
	FOR(i,0,n)FOR(j,0,m)dp[i][j]=1e9;
	dp[0][0]=0;
	rep(i,0,26)nxt[n+1][i]=n+1,nxt2[m+1][i]=m+1;
	for(int i=n;i>=1;i--){
		rep(j,0,26){
			nxt[i][j]=nxt[i+1][j];
		}
		nxt[i][s[i]-'a']=i;
	}
	for(int i=m;i>=1;i--){
		rep(j,0,26){
			nxt2[i][j]=nxt2[i+1][j];
		}
		nxt2[i][c[i]-'a']=i;
	}
	FOR(i,0,n){
		FOR(j,0,m){
			if(i<n&&j<m){
				if(s[i+1]==c[j+1])gmin(dp[i+1][j+1],dp[i][j]); 
				else gmin(dp[i+1][j+1],dp[i][j]+tr);
			}
			gmin(dp[i][j+1],dp[i][j]+ti);
			gmin(dp[i+1][j],dp[i][j]+td);
			if(i+2<=n&&j+2<=m){
				int t=nxt[i+2][c[j+1]-'a'],t2=nxt2[j+2][s[i+1]-'a'];
				if(t!=n+1&&t2!=m+1){
					gmin(dp[t][t2],dp[i][j]+td*(t-i-2)+te+ti*(t2-j-2));
				}
			}
		}
	}
	cout<<dp[n][m];
	RE 0;
}