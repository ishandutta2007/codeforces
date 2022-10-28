#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int)v.size()
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
const int MAXN = 4e3+10, MAXM = 2e5+10, MAXL = 20, ALP = 26, INF = 1e9+10, MOD = 1e9+7, MAXK = 810;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
// const ll INF = 1e18+10;

ll po(ll b, ll p){
    ll r=1;
    for (; p; p=(p>>1), b=b*b) if (p&1) r = r*b;
    return r;
}

void solve(){
    int n, x, cnt[3]={}; cin >> n >> x;
    vector<int> a(n, 0); for (auto& it : a) cin >> it, it = (it < x ? 0 : (it == x ? 1 : 2)), cnt[it]++;
    bool bad = 0; for (auto it : a) bad |= (it != 1);
    if (!bad) { cout << yes; return; }
    if (!cnt[1]) { cout << no; return; }
    for (int i = 0; i < n; i++){
        for (int j = i+1; j <= i+2 && j < n; j++){
            if (a[i] > 0 && a[j] > 0) { cout << yes; return; }
        }
    }
    cout << no;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1; 
    cin >> t; 
    while (t--) solve();
}