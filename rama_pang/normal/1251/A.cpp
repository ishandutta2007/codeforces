#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        map<char, int> mp;

        for (auto i : s) {
            mp[i] = 0;
        }

        for (int i = 0; i < s.size(); i++) {
            int cur = i;
            while (i + 1 < s.size() && s[i + 1] == s[cur]) i++;
            if ((i - cur + 1) % 2 == 1) {
                mp[s[i]] = 1;
            }
        }

        string res;
        for (auto i : mp) {
            if (i.second == 1) {
                res.push_back(i.first);
            }
        }
        cout << res << "\n";
    }
    return 0;
}