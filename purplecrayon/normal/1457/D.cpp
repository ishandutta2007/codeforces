#include "bits/stdc++.h"
using namespace std;

template<class T> using min_pq=priority_queue<T, vector<T>, greater<T>>;

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 5e3+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

int hsb(ll x){
    return 63-__builtin_clzll(x);
} 
void solve(){
    //if >= 3 things have the same highest set bit -> can do it in 1
    //otherwise n <= 60, bf l, m, r
    int n; cin >> n;
    vector<ll> a(n);
    for (auto& it : a) cin >> it;
    int cnt[32]={};
    for (auto& it : a) cnt[hsb(it)]++;
    if (*max_element(cnt, cnt+32) > 2){
        cout << "1\n";
        return;
    }
    assert(n <= 100);
    int ans=1e9;
    for (int l = 0; l < n; l++){
        ll tx=0;
        for (int r = l; r < n; r++){
            tx ^= a[r];
            ll mx=0;
            for (int m = l; m < r; m++){
                mx ^= a[m];
                if (mx > (tx^mx)) ans = min(ans, r-l-1);
            }
        }
    }
    cout << (ans>=1e9?-1:ans) << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    //cin >> t;
    while (t--) solve();
}