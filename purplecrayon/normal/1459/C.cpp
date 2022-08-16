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
const int MAXN = 1e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

void solve(){
    int n, q; cin >> n >> q;
    ll g=0;
    vector<ll> a(n);
    for (auto& it : a) cin >> it;
    for (int i = 1; i < n; i++) g = gcd(g, abs(a[i]-a[i-1]));
    while (q--){
       ll x; cin >> x;
       if (n == 1) cout << a[0]+x << ' ';
       else cout << gcd(a[0]+x, g) << ' ';
    }

}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    //cin >> t;
    while (t--) solve(); 
}