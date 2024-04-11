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
#define chkmax(a,b) a=max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 4e18, MOD = 1e9+7;

int solve(){
    int n,u,v; cin>>n>>u>>v;
    int ans = INF;
    vi a(n);
    loop(i,0,n) cin>>a[i];
    loop(i,0,n-1){
        if (a[i]!=a[i+1]) {
            chkmin(ans, u);
            if (abs(a[i]-a[i+1])>1) ans = 0;
            else chkmin(ans, v);
        }
        else {
            chkmin(ans, u+v);
            chkmin(ans, 2*v);
        }
    }
    cout << ans << endl;
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
3
2 3 4
2 2
2 3 4
3 2
2 4 3
3 2


*/