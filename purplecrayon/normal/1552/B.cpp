#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 4e5+10, MOD = 1e9+7; 

void solve(){
    int n; cin >> n;
    vector<ar<int, 5>> a(n);
    for (auto& c : a) for (auto& r : c) cin >> r, --r;

    int c = 0;
    for (int i = 1; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < 5; j++) if (a[i][j] < a[c][j]) {
            cnt++;
        }
        if (cnt >= 3) c = i;
    }
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < 5; j++) if (a[i][j] < a[c][j]) {
            cnt++;
        }
        if (cnt >= 3) { cout << -1 << '\n'; return; }
    }
    cout << c+1 << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}