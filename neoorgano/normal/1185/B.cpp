#include <bits/stdc++.h>
using namespace std;

main() {
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        string t;
        cin >> t;
        vector<pair<char, int>> vs, vt;
        for (auto ch : s) {
            if (vs.empty()) {
                vs.push_back({ch, 1});
            } else if (vs.back().first != ch) {
                vs.push_back({ch, 1});
            } else {
                vs.back().second++;
            }
        }
        for (auto ch : t) {
            if (vt.empty()) {
                vt.push_back({ch, 1});
            } else if (vt.back().first != ch) {
                vt.push_back({ch, 1});
            } else {
                vt.back().second++;
            }
        }
        if (vs.size() != vt.size()) {
            cout << "NO\n";
            continue;
        }
        bool f = true;
        for (int i = 0; i < vs.size(); ++i) {
            if (vs[i].first != vt[i].first) {
                f = false;
            }
            if (vs[i].second > vt[i].second) {
                f = false;
            }
        }
        if (f) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}