#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse4,avx2")
#pragma GCC optimize("unroll-loops,O2")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define all(x) (x).begin() , (x).end()
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pll;
constexpr int N = 3e3+20,mod = 1e9+7,inf = 1e9+10;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
 
inline int poww(int a,int k){
    if (k < 0) return 0;
    int z = 1;
    while (k){
        if (k&1) z = 1ll*z*a%mod;
        a = 1ll*a*a%mod;
        k >>= 1;
    } 
    return z; 
}
ll calc[N],ans,tmp[N];
vector<ll> pre[N];
int sz[N],n,k;
void solve(int l,int r){
    if (r-l == 1){
        int R = min(k,sz[l])+1;
        ans = max(ans,calc[k]);
        rep(i,1,R){
            ans = max(ans,calc[k-i]+pre[l][i-1]);
        }
        return;
    }
    vector<ll> tmp;
    rep(i,0,k+1) tmp.pb(calc[i]);
    int m = (l+r) >> 1;
    rep(i,l,m){
        repr(j,k,0){
            if (j >= sz[i]) calc[j] = max(calc[j],calc[j-sz[i]]+pre[i].back());
        }
    }
    solve(m,r);
    rep(i,0,k+1) calc[i] = tmp[i];
    rep(i,m,r){
        repr(j,k,0){
            if (j >= sz[i]) calc[j] = max(calc[j],calc[j-sz[i]]+pre[i].back());
        }
    }
    solve(l,m);
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    rep(i,0,n){
        cin >> sz[i];
        rep(j,0,sz[i]){
            int x;
            cin >> x;
            if (!j) pre[i].pb(x);
            else pre[i].pb(x+pre[i][j-1]);
        }
    }
    solve(0,n);
    cout << ans;
}