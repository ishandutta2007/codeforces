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
        string s, t;
        cin >> s >> t;

        bool can = true;

        vector<pair<int, int>> ans;
        for (int i = 0; i < n; i++) {
            if (s[i] == t[i]) {
                continue;
            }
            bool done = false;
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) {
                    swap(s[j], t[i]);
                    ans.emplace_back(j, i);
                    done = true;
                    break;
                }
            }
            if (done) {
                continue;
            }
            for (int j = i + 1; j < n; j++) {
                if (s[i] == t[j]) {
                    swap(s[j], t[j]);
                    swap(s[j], t[i]);
                    ans.emplace_back(j, j);
                    ans.emplace_back(j, i);
                    done = true;
                    break;
                }
            }
            if (done) {
                continue;
            }
            can = false;
            break;
        }
        if (!can) {
            cout << "No\n";
            continue;
        }

        cout << "Yes\n";
        cout << ans.size() << "\n";
        for (auto i : ans) {
            cout << i.first + 1 << " " << i.second + 1 << "\n";
        }
    }
}