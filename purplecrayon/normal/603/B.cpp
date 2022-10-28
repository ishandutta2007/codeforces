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
const int MAXN = 2e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const ll INF = 1e18+10;

ll po(ll b, ll p){
    ll r=1;
    for (; p; b=b*b%MOD, p/=2) if (p&1) r=r*b%MOD;
    return r;
}
void solve(){
    ll p, k; cin >> p >> k;
    if (!k) cout << po(p, p-1) << '\n';
    else if (k == 1) cout << po(p, p) << '\n';
    else {
        ll c=1;
        for (ll cp = k; cp != 1; c++) cp = cp*k%p;
        cout << po(p, (p-1)/c) << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t;
    while (t--) solve();
}