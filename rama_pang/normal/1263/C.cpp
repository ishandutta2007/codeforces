#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);


    int t; cin >> t;
    while (t--) {
        lint n; cin >> n;
        vector<lint> ans;
        ans.emplace_back(0);

        for (int i = 1; i <= n; i++) {
            lint nxt = i;
            lint le = i, ri = n;
            while (le <= ri) {
                lint mid = (le + ri) / 2;
                if ((n / mid) != (n / i)) {
                    ri = mid - 1;
                } else {
                    le = mid + 1;
                    nxt = mid;
                }
            }
            i = nxt;
            ans.emplace_back(n / i);
            
        }
        
        sort(ans.begin(), ans.end());
        ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
        cout << ans.size() << "\n";
        for (auto i : ans) cout << i << " ";
        cout << "\n";


    }

}