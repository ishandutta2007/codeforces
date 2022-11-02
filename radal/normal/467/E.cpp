#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pll;
constexpr int N = 1e6+20,mod = 1e9+7,inf = 1e9+10;
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
vector<int> ind[N],b;
int lz[N*4],a[N],c[N];

void upd(int l,int r,int s,int e, int x,int v = 1){
    if (l >= s && r <= e){
        lz[v] = x;
        return;
    }
    if (lz[v] || s >= e || l >= e || s >= r) return;
    int m = (l+r) >> 1,u = (v << 1);
    upd(l,m,s,e,x,u);
    upd(m,r,s,e,x,u|1);
}

int que(int l,int r,int p,int v = 1){
    if (lz[v]) return lz[v];
    if (r-l == 1) return 0;
    int m = (l+r) >> 1,u = (v << 1);
    if (p < m) return que(l,m,p,u);
    else return que(m,r,p,u|1);
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    rep(i,0,n){
        cin >> a[i];
        b.pb(a[i]);
    }
    sort(b.begin(),b.end());
    rep(i,0,n)
        c[i] = lower_bound(b.begin(),b.end(),a[i])-b.begin()+1;
    vector<int> ans;
    int l = 0;
    rep(i,0,n){
        if (ind[c[i]].empty()){
            ind[c[i]].pb(i);
            continue;
        }
        bool ok = 0;
        for (int j : ind[c[i]]){
            int x = que(0,n,j);
            if (x){
                ans.pb(x);
                ans.pb(a[i]);
                ans.pb(x);
                ans.pb(a[i]);
                while (l <= i){
                    ind[c[l]].clear();
                    l++;
                }
                ok = 1;
                break;
            }
        }
        if (ok) continue;
        upd(0,n,ind[c[i]][0]+1,i,a[i]);
        ind[c[i]].pb(i);
    }
    cout << ans.size() << endl;
    for (int u : ans) cout << u << ' ';
}