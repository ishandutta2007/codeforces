#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    
    if (n == 1) {
        cout << "? 1 1" << endl;
        string ans;
        cin >> ans;

        cout << "! " << ans << endl;
        return 0;
    }

    map<string, int> prefix;
    /*  Ask [1, n], and [2, n]. Sort substrings, then delete occurences of [2, n] from [1, n],
        and we will get prefixes of the original string. Then it's simply concatenating them.
     */

    int cnt = n * (n + 1) / 2;
    cout << "? 1 " << n << endl;
    for (int i = 0; i < cnt; i++) {
        string s;
        cin >> s;
        sort(begin(s), end(s));
        prefix[s]++;
    }

    cnt = (n - 1) * (n) / 2;
    cout << "? 2 " << n << endl;
    for (int i = 0; i < cnt; i++) {
        string s;
        cin >> s;
        sort(begin(s), end(s));
        prefix[s]--;
    }
    vector<string> prefixes;
    for (auto &i : prefix) {
        if (i.second > 0) {
            prefixes.emplace_back(i.first);
        }
    }

    string ans;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (prefixes[j].size() == i + 1) {
                int alp[26] = {};
                for (int k = 0; k < prefixes[j].size(); k++) {
                    alp[prefixes[j][k] - 'a']++;
                }
                for (int k = 0; k < ans.size(); k++) {
                    alp[ans[k] - 'a']--;
                }
                for (int k = 0; k < 26; k++) {
                    if (alp[k] == 1) {
                        ans.push_back(k + 'a');
                        break;
                    }
                }
            }
        }
    }

    cout << "! " << ans << endl;
    return 0;

}