/*


DP





ll int
 dp 









*/
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
char c[155];
int dp[155][55][55][55],mod=51123987;
int nxt[155][3];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int ans=0;
    FOR(i,1,n){
        cin>>c[i];
    }
    nxt[n+1][0]=nxt[n+1][1]=nxt[n+1][2]=n+1;
    for(int i=n;i>=1;i--){
        rep(j,0,3){
            nxt[i][j]=nxt[i+1][j];
        }
        nxt[i][c[i]-'a']=i;
    }
    dp[1][0][0][0]=1;
    int m=(n+2)/3;
    FOR(i,1,n){
        FOR(p1,0,m){
            FOR(p2,0,m){
                FOR(p3,0,m){
                    if(p1+p2+p3==n&&max(max(p1,p2),p3)-min(min(p1,p2),p3)<=1){
                        ans=(ans+dp[i][p1][p2][p3])%mod;
                    }
                    dp[nxt[i][0]][p1+1][p2][p3]=(dp[nxt[i][0]][p1+1][p2][p3]+
                    dp[i][p1][p2][p3])%mod;
                    dp[nxt[i][1]][p1][p2+1][p3]=(dp[nxt[i][1]][p1][p2+1][p3]+
                    dp[i][p1][p2][p3])%mod;
                    dp[nxt[i][2]][p1][p2][p3+1]=(dp[nxt[i][2]][p1][p2][p3+1]+
                    dp[i][p1][p2][p3])%mod;
                }
            }
        }
    }
    cout<<ans;
    RE 0;
}