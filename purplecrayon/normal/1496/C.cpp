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
const int MAXN = 2e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
 
void solve(){
    int n; cin >> n;
    vector<ll> a, b;
    for (int _ = 0; _ < 2*n; _++){
        ll x, y; cin >> x >> y;
        if (x == 0){
            a.push_back(abs<ll>(y));
        } if (y == 0){
            b.push_back(abs<ll>(x));
        }
    }
    assert(sz(a) == n && sz(b) == n);
    sort(a.begin(), a.end()), sort(b.begin(), b.end());
    ld ans=0;
    for (int i = 0; i < n; i++){
        ans += sqrt(a[i]*a[i] + b[i]*b[i]);
    }
    cout << fixed << setprecision(20) << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    cin >> t_c;
    while (t_c--) solve();
}