#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
const int MAXN = 2e5+10, MAXM = 2e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 810;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const ll INF = 9e18+10;

void solve(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (auto& it : a) cin >> it;
    for (auto& it : b) cin >> it;
    vector<int> good(2, 0);
    for (int i = 0; i < n; ++i) {
        if (a[i] > b[i] && !good[0]) { cout << no; return; }
        if (a[i] < b[i] && !good[1]) { cout << no; return; }
        if (a[i] == -1) good[0] = 1;
        if (a[i] == 1) good[1] = 1;
    }
    cout << yes;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t; 
    while (t--) solve();
}