#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int ntest; cin >> ntest;
    while(ntest--) {
        int n; cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        int ans = 0;
        for(int i = 0; i + 1 < n; ++i) {
            int x = min(a[i], a[i + 1]), y = max(a[i], a[i + 1]);
            while(x * 2 < y) {
                x *= 2;
                ans += 1;
            }
        }
        cout << ans << endl;
    }

    return 0;
}