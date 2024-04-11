#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t; cin >> t;
    int A[200005];
    map<int, int> mp;

    while (t--) {
        int n; mp.clear();
        cin >> n;
        int ans = 1e9;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
            if (mp[A[i]] == 0) mp[A[i]] = i;
            else {
                ans = min(ans, i - mp[A[i]] + 1);
                mp[A[i]] = i;
            }
        }
        if (ans == 1e9) ans = -1;
        
        cout << ans << "\n";

    }
    
}