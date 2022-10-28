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
    int n; ll k; cin >> n >> k;
    vector<ll> a(n); for (auto& it : a) cin >> it;
    ll lo=a[0], hi=a[0];
    for (int i = 1; i < n; i++){
        lo = min(lo, lo-k+1); lo = max(lo, a[i]); 
        hi = max(hi, hi+k-1); hi = min(hi, a[i]+k-1);
        if (hi < lo){ cout << no; return; }
    }
    if (lo <= a[n-1] && a[n-1] <= hi) cout << yes;
    else cout << no;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t;
    while (t--) solve(); 
}