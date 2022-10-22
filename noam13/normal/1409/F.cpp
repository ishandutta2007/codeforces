#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define vb vector<bool>
#define ii pair<int,int>
#define vvi vector<vi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define loop(i,s,e) for(int i=s;i<e;i++)
#define loopr(i,s,e) for(int i=e-1;i>=s;i--)
#define chkmax(a,b) a=max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 2e18, MOD=1e9+9;


int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,k; cin>>n>>k;
    string s, t; cin>>s>>t;
    if (t[0]==t[1]){
        int ans = 0;
        loop(i,0,n) ans+=(s[i]==t[0]);
        ans = min(n, ans+k);
        ans = (ans * (ans-1))/2;
        cout<<ans<<endl;
        return 0;
    }
    const int N = 203;
    int dp[N][N][N] = {0};
    loop(i,0,n+1) loop(j,0,n+1) loop(a,0,k+1) dp[i][j][a] = -INF;
    dp[0][0][0] = 0;
    loop(i,0,n){
        loop(j,0,i+1){
            loop(x,0,k+1){
                if (dp[i][j][x]==-INF) continue;
                chkmax(dp[i+1][j+1][x+(s[i]!=t[0])], dp[i][j][x]);
                chkmax(dp[i+1][j][x+(s[i]!=t[1])], dp[i][j][x]+j);
                if (s[i]!=t[0] && s[i]!=t[1]){
                    chkmax(dp[i+1][j][x], dp[i][j][x]);
                }
            }
        }
    }
    int ans = 0;
    loop(j,0,n+1) loop(x,0,k+1) chkmax(ans, dp[n][j][x]);
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ temp2.cpp -o a & a
4 2
bbaa
ab

*/