#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<long long> h(n);
    for (auto& it : h) cin >> it;
    for (int i = 0; i < n; i++) {
        if (h[i] < i) { cout << "NO\n"; return; }
        if (i < n-1) h[i+1] += h[i]-i;
    }
    cout << "YES\n";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) solve();
}