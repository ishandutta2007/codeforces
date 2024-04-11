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
    vii a(m);
    vi x(n+1,-1),y(n+1,-1);
    loop(i,0,m) cin>>a[i].x>>a[i].y, x[a[i].x] = i;
    int ans = 0;
    vb check(m);
    loop(i,0,m){
        if (check[i]) continue;
        if (a[i].x==a[i].y) continue;
        int j = i;
        //cout<<"HI: "<<endl;
        while(j!=-1 && !check[j]){
            check[j] = 1;
            ans++;
            j = x[a[j].y];
        }
        if (j==i) ans++;
    }
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
4
3 1
2 3
3 2
2 1
1 2
5 3
2 3
3 1
1 2
5 4
4 5
5 1
2 2
3 3



*/