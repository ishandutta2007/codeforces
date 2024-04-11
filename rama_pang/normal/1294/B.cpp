#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string ans;
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].first >> a[i].second;
        }
        sort(begin(a), end(a), [&](pair<int, int> a, pair<int, int> b) {
            return a.first + a.second < b.first + b.second;
        });
        pair<int, int> cur = {0, 0};
        for (int i = 0; i < n; i++) {
            while (cur.first < a[i].first) {
                ans.push_back('R');
                cur.first++;
            }
            while (cur.second < a[i].second) {
                ans.push_back('U');
                cur.second++;
            }
            
            if (cur.first > a[i].first || cur.second > a[i].second) {
                ans = "";
                cout << "NO\n";
                break;
            }
        }
        if (!ans.empty()) {
            cout << "YES\n";
            cout << ans << "\n";
        }
    }

}