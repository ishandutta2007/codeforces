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

int solve(){
    int n; cin>>n;
    int m = 2*n;
    vi p(m); loop(i,0,m) cin>>p[i];
    vi sz;
    int cur = 1, max = p[0];
    loop(i,1,m){
        if (p[i]>max) sz.pb(cur), cur=1, max=p[i];
        else cur++;
    }
    sz.pb(cur);
    //cout<<"SZ: ";for(auto x:sz) cout<<x<<" "; cout<<endl;
    vb dp(n+1,0); dp[0]=1;
    for(auto x:sz){
        loopr(i,x,n+1) if(dp[i-x]) dp[i]=1;
    }
    cout<<(dp[n]?"YES":"NO")<<endl;
    return 0;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int t; cin>>t;
    loop(i,0,t) solve();
    return 0;
}
/*
color a
cls
g++ b.cpp -o a & a
6
2
2 3 1 4
2
3 1 2 4
4
3 2 6 1 5 7 8 4
3
1 2 3 4 5 6
4
6 1 3 7 4 5 8 2
6
4 3 2 5 1 11 9 12 8 6 10 7

*/