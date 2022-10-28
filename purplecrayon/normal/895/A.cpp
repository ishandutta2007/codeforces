#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n); for (auto& it : a) cin >> it;
    int ans = 1e9;
    for (int i = 0; i < n; i++) {
        for (int l = 0; l < n; l++) {
            int sm = 0;
            for (int r = l; r < n; r++) {
                sm += a[r];
                
                ans = min(ans, abs((360-sm)-sm));
            }
        }
        
        int x = a.back(); a.pop_back();
        a.insert(a.begin(), x);
    }
    cout << ans << '\n';
}