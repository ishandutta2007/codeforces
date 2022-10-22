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
    int n,w; cin>>n>>w;
    vii a(n); loop(i,0,n) cin>>a[i].x, a[i].y = i;
    sort(all(a));
    reverse(all(a));
    int c =0;
    vi ans;
    for(auto x:a){
        if (c+x.x<=w){
            ans.pb(x.y);
            c+=x.x;
        }
    }
    if (c>=(w+1)/2){
        cout<<ans.size()<<endl;
        for(int x:ans) cout<<x+1<<" ";
        cout<<endl;
    }
    else cout<<-1<<endl;
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
3
1 3
3
6 2
19 8 19 69 9 4
7 12
1 1 1 17 1 1 1

*/