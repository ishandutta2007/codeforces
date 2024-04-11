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
typedef long long ll;
typedef pair<int,int> pll;
const long long int N=8e5+20,mod = 1e9+7,inf=1e18,dlt = 12250,maxm = 2e6;
int poww(ll a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    ll r = poww(a,k/2);
    return (((r*r)%mod)*poww(a,k&1))%mod;
}
int hsh[30],a[30];
bool mark[30];
inline int mkay(int v){
    if (v >= mod) return v-mod;
    return v;
}
inline bool check(){
    rep(i,0,29){        
        if (hsh[i] == a[i] || mark[i]) continue;
        bool f = 0;
        rep(j,i+1,29){
            if (mark[j]) continue;
            if (a[j] == hsh[i] && a[i] == hsh[j]){
                f = 1;
                mark[j] = 1;
                mark[i] = 1;
                break;
            }
        }
        if (!f){
            rep(j,0,29) mark[j] = 0;
            return 0;
        }
    }
    rep(i,0,29) mark[i] = 0;
    return 1;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    string s,t;
    cin >> n >> m >> s >> t;
    rep(i,0,m){
        int d = t[i]-'a';
        a[d] += poww(31,m-i-1);
        a[d] %= mod;
    }
    rep(i,0,m){
        int d = s[i]-'a';
        hsh[d] += poww(31,m-i-1);
        hsh[d] = mkay(hsh[d]);
    }
    vector<int> ve;
    if (check())
        ve.pb(1);
    int o = poww(31,m-1);
    rep(i,1,n-m+1){
        int d = s[i-1]-'a';
        hsh[d] = mkay(hsh[d]+mod-o);
        rep(j,0,29)
            hsh[j] = (1ll*hsh[j]*31)%mod;
        d = s[i+m-1]-'a';
        hsh[d] ++;
        hsh[d] = mkay(hsh[d]);
        if (check()) ve.pb(i+1);
    }
    cout << ve.size() << endl;
    for (int u : ve) cout << u << ' ';
}