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
    int n; cin >> n; 

    vector<ll> a(n); for (auto& it : a) cin >> it;
    vector<ll> v; v.reserve(n); vector<int> deg(n);
    for (int i = 0; i < n-1; i++){
        int x, y; cin >> x >> y, --x, --y;
        if (deg[x]) v.push_back(a[x]);
        if (deg[y]) v.push_back(a[y]);
        deg[x]++, deg[y]++;
    }
    ll ans=accumulate(a.begin(), a.end(), 0ll);
    cout << ans << ' '; sort(v.rbegin(), v.rend());
    for (auto& it : v) ans += it, cout << ans << ' ';
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t;
    while (t--) solve();
}