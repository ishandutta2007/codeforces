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

int n;
ll a[MAXN], ps[MAXN];
set<ll> s;

void rec(int l, int r){
    s.insert(ps[r]-(l?ps[l-1]:0));
    if (a[l] == a[r]){
        return;
    }
    ll mv = (a[l]+a[r])/2;
    int m = upper_bound(a+l, a+r+1, mv)-a;
    rec(l, m-1), rec(m, r);
}
void solve(){
    int q; cin >> n >> q; s.clear();
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a+n);
    for (int i = 0; i < n; i++){
        ps[i] = a[i]+(i?ps[i-1]:0ll);
    }
    rec(0, n-1);
    while (q--){
        ll c; cin >> c;
        if (s.find(c) != s.end()) cout << "Yes\n";
        else cout << "No\n";
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t;
    while (t--) solve();
}