#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,sse4,avx2")
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
constexpr int N = 2e5+20,mod = 1e9+7,inf = 1e9+10;
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
map<int,int> pr,par;
int getpar(int v){
    if (par[v] == v) return v;
    getpar(par[v]);
    pr[v] ^= pr[par[v]];
    par[v] = par[par[v]];
    return par[v];
}
inline void ad(int i){
    if (pr.find(i) == pr.end()){
        pr[i] = 0;
        par[i] = i;
    }
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    pr[0] = 0;
    par[0] = 0;
    int q,last = 0;
    cin >> q;
    while (q--){
        int t,ll,rr,xx;
        cin >> t >> ll >> rr;
        int l = ll^last,r = rr^last;
        if (l > r) swap(l,r);
        ad(r);
        ad(l-1);
        if (t == 1){
            cin >> xx;
            int x = xx^last;
            if (getpar(r) == getpar(l-1)) continue;
            if (par[r] > par[l-1]){
                pr[par[r]] = pr[l-1]^pr[r]^x;
                par[par[r]] = par[l-1];
            }
            else{
                pr[par[l-1]] = pr[l-1]^x^pr[r];
                par[par[l-1]] = par[r];
            }
            continue;
        }
        if (getpar(r) != getpar(l-1)){
            last = 1;
            cout << -1 << endl;
            continue;
        }
        last = pr[r]^pr[l-1];
        cout << last << endl;
    }
}