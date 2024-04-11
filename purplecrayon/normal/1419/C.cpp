#include "bits/stdc++.h"
using namespace std;

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
    int n; ll x; cin >> n >> x;
    vector<ll> a(n); for (auto& it : a) cin >> it;
    if (*min_element(a.begin(), a.end()) == x && *max_element(a.begin(), a.end()) == x){ cout << "0\n"; return; }
    if (count(a.begin(), a.end(), x)){ cout << "1\n"; return; }
    if (accumulate(a.begin(), a.end(), 0ll)==x*n) { cout << "1\n"; return; }
    cout << "2\n";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t;
    while (t--) solve();
}