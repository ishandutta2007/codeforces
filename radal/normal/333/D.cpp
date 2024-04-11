#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O8")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long  int ll;
typedef pair<ll,ll> pll;
const long long int N=1e3+20,mod = 1e9+7,inf=2e9,maxq = 1e5+30;
const long double eps = 0.0000001;
ll poww(ll a, ll b) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % mod, b / 2) % mod : poww(a * a % mod, b / 2) % mod));
}
int n,m;
int a[N][N];
bool b[N][N],vis[N][N];
set<pair<int,int> > st;
bool check(int val){
    memset(vis,0,sizeof vis);
    rep(i,0,n){
        rep(j,0,m){
            if (a[i][j] >= val) b[i][j] = 1;
            else b[i][j] = 0;
        }
    }
    rep(i,0,n){
        vector<int> ve;
        int sz = 0;
        rep(j,0,m) if (b[i][j]) ve.pb(j),sz++; 
        rep(j,0,sz){
            rep(k,j+1,sz){
                if (vis[ve[j]][ve[k]]){
                    return 1;
                }
                vis[ve[j]][ve[k]] = 1;
            }
        }
    }
    return 0;
}
int binary(int l,int r){
    if (check(r)) return r;
    int mid;
    while (r-l > 1){
        mid = (l+r)/2;
        if (check(mid)) l = mid;
        else r = mid;
    }
    return l;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    rep(i,0,n) rep(j,0,m) cin >> a[i][j];
    cout << binary(0,1000000000);
    return 0;
}