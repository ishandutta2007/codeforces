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
const int MAXN = 1e5+10, MAXM = 1e2+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

void solve(){
    int n; cin >> n;
    vector<ll> a(n);
    for (auto& it : a) cin >> it;
    sort(a.begin(), a.end());
    if (n > 10){
        vector<ll> b;
        for (int i = 0; i < 5; i++) b.push_back(a[i]);
        for (int i = n-5; i < n; i++) b.push_back(a[i]);
        a = b;
    }
    n = sz(a);
    ll ans=-1e18;
    for (int i = 0; i < (1<<n); i++) if (__builtin_popcount(i) == 5) {
        ll c=1;
        for (int j = 0; j < n; j++) if (i&(1<<j)) c = c*a[j];
        ans = max(ans, c);
    }
    cout << ans << "\n";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t;
    while (t--) solve();
}