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
    vector<ar<int, 3>> op; op.reserve(n);
    if (n&1){
        for (int rep = 0; rep < 2; rep++) for (int i=1; i+1 < n; i+=2) op.push_back({0, i, i+1});
    } else {
        ll x=0; for (auto& it : a) x ^= it;
        if (x) { cout << no; return; }
        for (int rep = 0; rep < 2; rep++) for (int i=1; i+1 < n-3; i+=2) op.push_back({0, i, i+1});
        op.push_back({n-3, n-2, n-1});
    }
    cout << yes;
    cout << sz(op) << '\n';
    assert(sz(op) <= n);
    for (auto& it : op){
        ll x=0;
        for (auto& i : it) x ^= a[i];
        for (auto& i : it) a[i] = x;
    }
    assert(*max_element(a.begin(), a.end()) == *min_element(a.begin(), a.end()));
    for (auto& it : op){
        for (auto& i : it) cout << i+1 << ' ';
        cout << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    //cin >> t;
    while (t--) solve();
}