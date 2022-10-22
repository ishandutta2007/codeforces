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
int n,m,k;
int dp[2][1<<22];
int p[800],nxt[1<<22];
bool f[1<<22];
double ST=clock()+CLOCKS_PER_SEC*3.9;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>k;
    if(m>k)swap(m,k);
    int now=1;
    int lst=n%(m+k);
    rep(mask,0,(1<<k)){
        f[mask]=!(mask&(1<<(k-1)))&&!(mask&(1<<(m-1)));
        nxt[mask]=(mask<<1)&((1<<k)-1);
    }
    int lstp=0,top=14;
    int ff=0;
    FOR(i,1,top*(m+k)+lst){
        FILL(dp[now],0);
        rep(mask,0,(1<<k)){
            if(f[mask]){
                gmax(dp[now][nxt[mask]|1],dp[now^1][mask]+1);
            }
            gmax(dp[now][nxt[mask]],dp[now^1][mask]);
        }
        p[i]=*max_element(dp[now],dp[now]+(1<<k));
        now^=1;
        if(clock()>ST){
            top=(i-lst)/(m+k);break;
        }
        // cout<<p[i]<<' ';
    }
    if(top*(m+k)+lst>=n){
        cout<<p[n];RE 0;
    }
    int t=p[top*(m+k)+lst]-p[(top-1)*(m+k)+lst];
    // cout<<t<<'\n';
    int ans=t*(n/(m+k)-top);
    ans+=p[top*(m+k)+lst];
    cout<<ans;
    RE 0;
}