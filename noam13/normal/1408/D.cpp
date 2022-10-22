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
    int n,m; cin>>n>>m;
    vii a(n), b(m);
    loop(i,0,n) cin>>a[i].x>>a[i].y;
    loop(i,0,m) cin>>b[i].x>>b[i].y;
    vii dist;
    loop(i,0,n) loop(j,0,m){
        if (a[i].x>b[j].x || a[i].y > b[j].y) continue;
        dist.pb({b[j].x-a[i].x+1, b[j].y-a[i].y+1});
    }
    if (dist.size()==0) return cout<<0<<endl,0;
    int best = INF, maxp = 0;
    sort(all(dist)); reverse(all(dist));
    for(auto p:dist){
        chkmin(best, p.x + maxp);
        chkmax(maxp, p.y);
    }
    chkmin(best, maxp);
    cout<<best<<endl;
    return 0;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
/*
color a
cls
g++ d.cpp -o a & a

*/