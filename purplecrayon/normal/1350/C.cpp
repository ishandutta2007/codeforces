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
    int n; cin >> n;
    vector<int> a(n, 0); for (auto& it : a) cin >> it;
    unordered_map<int, multiset<int>> p;
    for (int i = 0; i < n; i++){
        int c = a[i], oc = c;
        unordered_map<int, int> cc;
        for (int p=2; p*p<=oc; p++){
            while (c%p == 0){
                c /= p; cc[p]++;
            }
        }
        if (c > 1) cc[c]++;
        for (auto it : cc) p[it.first].insert(it.second);
    }
    ll ans = 1;
    for (auto& it : p){
        multiset<int>& m = it.second;
        if (sz(m) <= n-2) continue; //power will always be one
        if (sz(m) == n-1) {
            ans *= po(it.first, (*m.begin())); continue;
        }
        int cpo = (*next(m.begin()));
        ans *= po(it.first, cpo);
    }
    cout << ans << "\n";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1; 
    // cin >> t; 
    while (t--) solve();
}