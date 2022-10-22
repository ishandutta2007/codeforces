#include <bits/stdc++.h>
#define int int64_t
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
const int INF = 4e18;



int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,m; cin>>n>>m;
    string a,b; cin>>a>>b;
    vvi dp(n+2, vi(m+2));
    loop(i,0,n) loop(j,0,m) dp[i][j] = i+j;
    int ans = 0;
    loop(i,0,n+1) loop(j,0,m+1){
        if (a[i]==b[j]) chkmax(dp[i+1][j+1], dp[i][j]+4);
        chkmax(dp[i+1][j], dp[i][j]);
        chkmax(dp[i][j+1], dp[i][j]);
        chkmax(ans, dp[i][j] - i - j);
    }
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ b.cpp -o a & a
4 5
abba
babab

*/