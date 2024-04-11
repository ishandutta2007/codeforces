#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n, s, k;
        cin >> n >> s >> k;
        vector<int> a(k);
        set<int> st;
        for (int i = 0; i < k; i++) {
            cin >> a[i];
            st.emplace(a[i]);
        }
        for (int ans = 0; ans < 10000; ans++) {
            if (s + ans <= n && st.count(s + ans) == 0) {
                cout << ans << "\n";
                break;
            }
            if (s - ans >= 1 && st.count(s - ans) == 0) {
                cout << ans << "\n";
                break;
            }
            
        }
    }

}