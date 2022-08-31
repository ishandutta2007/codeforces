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
const int MAXN = 2e5, MAXQ = 3e5+10, MAXL = 18, ALP = 26, MOD = 1e9+7, MAXK = 17,  MAXA = 10, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const int INF = 1e9+10;


#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

void solve(){
    int n; cin >> n;
    vector<int> a(n); for (auto& it : a) cin >> it;
    ll ans=1e18;
    for (int i = 1; i*i <= a[0]; i++) {
        auto v = [&](int c) {
            if (c <= 0) return;

            ll cur = 0;
            for (int x : a) {
                if (x%c > x/c) return;
                cur += x/(c+1)+((x%(c+1))>0);
            }
            ans=min(ans, cur);
        };
        int d=a[0]/i;
        v(i-1), v(i), v(i+1), v(d-1), v(d), v(d+1);
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    //cin >> t_c;
    while (t_c--) solve();
}