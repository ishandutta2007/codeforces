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
    vi a(n); loop(i,0,n) cin>>a[i];
    vvi hist(n+1); loop(i,0,n) hist[a[i]].pb(i);
    vi ans(n+1,INF);
    loop(i,0,n+1){
        if (hist[i].size()==0) continue;
        int d = 0;
        loop(j,1,hist[i].size()) chkmax(d, hist[i][j] - hist[i][j-1]);
        chkmax(d, hist[i][0]+1);
        chkmax(d, n-hist[i].back());
        chkmin(ans[d], i);
    }
    loop(i,1,n+1) chkmin(ans[i], ans[i-1]);
    loop(i,1,n+1) cout<<(ans[i]==INF?-1:ans[i])<<" ";
    cout<<endl;
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
g++ a.cpp -o a & a

*/