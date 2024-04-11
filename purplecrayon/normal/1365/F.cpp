#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int)v.size()
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
const int MAXN = 60, MAXM = 1e5+10, ALP = 26, INF = 1e9+10, MOD = 1e9+7;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
// const ll INF = 1e18+10;

void solve(){
    int n; cin >> n;
    vector<ll> a(n), b(n);
    for (auto& it : a) cin >> it;
    for (auto& it : b) cin >> it;
    if (n%2 == 1 && a[n>>1] != b[n>>1]) { cout << no; return; }
    multiset<pair<int, int>> s;
    for (int i = 0, j = n-1; i+i < n; i++, j--){
        int aa = a[i], bb = a[j];
        if (aa < bb) swap(aa, bb);
        s.insert({aa, bb});
    }
    for (int i = 0, j = n-1; i+i < n; i++, j--){
        int aa = b[i], bb = b[j];
        if (aa < bb) swap(aa, bb);
        auto it = s.find({aa, bb});
        if (it == s.end()){ cout << no; return; }
        s.erase(it);
    }
    cout << yes; 
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1; 
    cin >> t; 
    while (t--) solve();
}