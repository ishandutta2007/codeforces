#include <bits/stdc++.h>
using namespace std;

const int MAXN = 27;
vector<int> larr[MAXN], rarr[MAXN];

main() {
    int n;
    cin >> n;
    string l, r;
    cin >> l >> r;
    for (int i = 0; i < n; ++i) {
        if (l[i] == '?') {
            l[i] = 'z' + 1;
        }
        if (r[i] == '?') {
            r[i] = 'z' + 1;
        }
        larr[l[i] - 'a'].push_back(i + 1);
        rarr[r[i] - 'a'].push_back(i + 1);
    }
    vector<pair<int, int>> ans;
    for (int i = 0; i < 26; ++i) {
        while (!larr[i].empty() && !rarr[i].empty()) {
            ans.push_back({larr[i].back(), rarr[i].back()});
            larr[i].pop_back();
            rarr[i].pop_back();
        }
    }
    vector<int> lef, rig;
    for (int i = 0; i < 26; ++i) {
        for (auto elem : larr[i]) {
            lef.push_back(elem);
        }
        for (auto elem : rarr[i]) {
            rig.push_back(elem);
        }
    }
    while (!lef.empty() && !rarr[26].empty()) {
        ans.push_back({lef.back(), rarr[26].back()});
        lef.pop_back();
        rarr[26].pop_back();
    }
    while (!rig.empty() && !larr[26].empty()) {
        ans.push_back({larr[26].back(), rig.back()});
        rig.pop_back();
        larr[26].pop_back();
    }
    while (!larr[26].empty() && !rarr[26].empty()) {
        ans.push_back({larr[26].back(), rarr[26].back()});
        larr[26].pop_back();
        rarr[26].pop_back();
    }
    cout << ans.size() << endl;
    for (auto elem : ans) {
        cout << elem.first << " " << elem.second << endl;
    }
    return 0;
}