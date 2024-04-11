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
const int INF = 4e18, MOD = 1e9+7;

int solve(){
    int n,m; cin>>n>>m;
    vi a(n); loop(i,0,n) cin>>a[i], a[i]--;
    sort(all(a));
    vi c(m); loop(i,0,m) cin>>c[i];
    int ans = 0;
    loop(i,0,n) ans += c[a[i]];
    int j = 0;
    loopr(i,0,n) if (j<a[i]) ans -= c[a[i]] - c[j++];
    cout<<ans<<endl;
    return 0;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int t=1; cin>>t;
    loop(i,0,t) solve();
    return 0;
}
/*
color a
cls
g++ a.cpp -o a & a
2
5 4
2 3 4 3 2
3 5 12 20
5 5
5 4 3 2 1
10 40 90 160 250

*/