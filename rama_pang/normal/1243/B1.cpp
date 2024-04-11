#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == t[i]) {
                continue;
            }
            cnt++;
        }
        if (cnt != 2) {
            cout << "No\n";
        } else {
            vector<int> aa;
            for (int i = 0; i < n; i++) {
                if (s[i] != t[i]) {
                    aa.emplace_back(i);
                }
            }
            if (s[aa[0]] == s[aa[1]] && t[aa[0]] == t[aa[1]]) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }
    }
}