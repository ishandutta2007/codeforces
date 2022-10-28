#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int)v.size()
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
const int MAXN = 1e5+10, MAXM = 1e5+10, ALP = 26, INF = 1e9+10, MOD = 1e9+7;
const int hA[4] = {1, 0, -1, 0}, kA[4] = {1, 0, -1, 0};
// const ll INF = 1e18+10;

void solve(){
    int n; cin >> n;
    vector<int> a(n); bool bad = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < n-1; i++) if (a[i] > a[i+1]) bad = 1;
    int cnt[2] = {0, 0};
    for (int i = 0; i < n; i++){
        int c; cin >> c; cnt[c]++;
    }
    if (!bad) { cout << "YES\n"; return; }
    if (cnt[0]&&cnt[1]) { cout << "YES\n"; return; }
    cout << "NO\n"; return;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1; cin >> t; while (t--) solve();
}