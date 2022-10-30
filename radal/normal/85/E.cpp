#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define ll long long int
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)

using namespace std;
typedef pair<int,int> pll;
const ll N = 5e3,mod=1e9+7;
pll guard[N];
int dep[N];
int vis[N];
bool dfs(int v,int d,int depth,int n,int t){
    vis[v] = t;
    dep[v] = depth;
    rep(i,0,n){
        if (i != v && abs(guard[i].X - guard[v].X)+abs(guard[i].Y - guard[v].Y) > d){
            if (!vis[i]) {
                if (!dfs(i,d,depth+1,n,t)) return 0;
            }
            else if (dep[i]%2 == dep[v]%2) return 0;
        }
    }
    return 1;
}
bool check(int d,int n){
    memset(vis, 0, sizeof vis);
    memset(dep, 0, sizeof dep);
    int t=0;
    rep (i,0,n){ 
        if (!vis[i]) {
            t++;
            if (!dfs(i,d,0,n,t)) return 0;
        }
    }
    return 1;
}
int binary(int l,int r,int n){
    if (check(l,n)) return l;
    int m = (l+r)/2;
    while (r-l > 1){
        if (check(m,n)){
            r = m;
        }
        else{
            l = m;
        }
        m = (r+l)/2;
    }
    return r;
}
int main()
{
    int n;
    cin >> n;
    rep(i,0,n) cin >> guard[i].X >> guard[i].Y;
    int d = binary(0,10001,n);
    cout << d << endl;
    ll ans=1;
    check(d,n);
    sort(vis,vis+n);
    int t = vis[n-1];
    rep(i,0,t){
        ans *= 2;
        ans %= mod;
    }
    cout << ans;

}