#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    vector<int> a(n); for (auto& it : a) cin >> it;
    vector<int> b(n); for (auto& it : b) cin >> it;
    
    int ans = 0, cur = 0;
    for (int i = 0; i < n; i++) ans += b[i]*a[i];
    
    vector<int> c(n); for (int i = 0; i < n; i++) if (!b[i]) c[i] = a[i];
    for (int i = 1; i < n; i++) c[i] += c[i-1];
    
    for (int i = 0; i+k <= n; i++) {
        int x = c[i+k-1]-(i?c[i-1]:0);
        cur = max(cur, x);
    }
    cout << ans+cur << '\n';
}