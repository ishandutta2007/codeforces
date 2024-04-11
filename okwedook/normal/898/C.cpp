#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool checksuff(string s, string suff) {
    int ptr1 = s.size() - 1, ptr2 = suff.size() - 1;
    while (ptr1 >= -1) {
        if (ptr2 == -1) return true;
        if (ptr1 == -1) return false;
        if (s[ptr1] == suff[ptr2]) {
            ptr1--;
            ptr2--;
        } else
            return false;
    }
    return false;
}

int main() {
    //ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    map<string, vector<string>> ans;
    string name, temp;
    for (int i = 0; i < n; ++i) {
        cin >> name;
        int count;
        cin >> count;
        for (int j = 0; j < count; ++j) {
            cin >> temp;
            ans[name].push_back(temp);
        }
    }
    cout << ans.size() << '\n';
    for (auto i : ans) {
        cout << i.first << ' ';
        vector<string> ansarr;
        vector<bool> used(i.second.size(), 0);
        for (int j = 0; j < i.second.size(); ++j)
            for (int k = 0; k < i.second.size(); ++k) {
                if (j == k || used[k]) continue;
                if (checksuff(i.second[k], i.second[j])) {
                    used[j] = true;
                    break;
                }
            }
        for (int j = 0; j < i.second.size(); ++j)
            if (!used[j])
                ansarr.push_back(i.second[j]);
        cout << ansarr.size() << ' ';
        for (auto j : ansarr) cout << j << ' ';
        cout << '\n';
    }
    //system("pause");
    return 0;
}