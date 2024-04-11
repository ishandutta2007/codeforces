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
        int cnt[2][2] = {};
        vector<string> s(n);
        set<string> all;
        for (int i = 0; i < n; i++) {
            cin >> s[i];
            cnt[s[i][0] - '0'][s[i].back() - '0']++;
            all.emplace(s[i]);
        }
        if (cnt[0][0] > 0 && cnt[1][1] > 0 && cnt[1][0] == 0 && cnt[0][1] == 0) {
            cout << -1 << "\n";
            continue;
        }
        vector<int> ans;
        if (cnt[1][0] > cnt[0][1] + 1) {
            for (int i = 0; i < n; i++) {
                if (s[i][0] == '1' && s[i].back() == '0') {
                    string ss(s[i].rbegin(), s[i].rend());
                    if (all.count(ss) == 0) {
                        ans.emplace_back(i);
                    }
                }
            }
        } else if (cnt[0][1] > cnt[1][0] + 1) {
            for (int i = 0; i < n; i++) {
                if (s[i][0] == '0' && s[i].back() == '1') {
                    string ss(s[i].rbegin(), s[i].rend());
                    if (all.count(ss) == 0) {
                        ans.emplace_back(i);
                    }
                }
            }
        }
        int k = max(0, (max(cnt[1][0], cnt[0][1]) - min(cnt[1][0], cnt[0][1])) / 2);
        cout << k << "\n";
        for (int i = 0; i < k; i++) {
            cout << ans[i] + 1 << " ";
        }
        cout << "\n";
    }

}