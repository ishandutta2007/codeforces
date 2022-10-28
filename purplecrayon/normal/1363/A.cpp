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
    int n, x; cin >> n >> x;
    int ans = 0;
    vector<int> a(n);
    int cnt1[2] = {0, 0}, cnt2[2] = {0, 0};
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if (i < x) ans += a[i], cnt1[a[i]&1]++;
        else cnt2[a[i]&1]++;
    }
    if (ans&1) { cout << yes; return; }
    if (cnt1[0] && cnt2[1]) { cout << yes; return; }
    if (cnt1[1] && cnt2[0]) { cout << yes; return; }
    cout << no;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1; 
    cin >> t; 
    while (t--) solve();
}