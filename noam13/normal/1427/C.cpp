#include <bits/stdc++.h>

#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define loop(i,s,e) for(int i=s;i<e;i++)
#define loopr(i,s,e) for(int i=e-1;i>=s;i--)
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 2e9;

int d(ii a, ii b){
    return abs(a.x-b.x) + abs(a.y-b.y);
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int r,n; cin>>r>>n;
    vii a(n+1); a[0] = {1,1};
    vi t(n+1);
    loop(i,1,n+1) cin>>t[i]>>a[i].x>>a[i].y;
    vi dp(n+1,-INF); dp[0] = 0;
    loop(i,1,n+1){
        loop(j,1,4*r+10){
            if (j>i) break;
            int k = i-j;
            if (d(a[i], a[k])<=t[i]-t[k]){
                //cout<<"IK"<<" "<<i<<" "<<k<<" "<<d(a[i], a[k])<<" "<<t[i]-t[k]<<endl;
                chkmax(dp[i], dp[k] + 1);
            }
        }
    }
    int ans = 0;
    //loop(i,0,n+1) cout<<dp[i]<<" "; cout<<endl;
    loop(i,0,n+1) chkmax(ans, dp[i]);
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ c.cpp -o a & a
10 4
1 2 1
5 10 9
13 8 8
15 9 9



*/