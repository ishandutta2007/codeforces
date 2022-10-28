#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        int n = (int) s.length();

        string answer;
        vector<int> freq(26);
        for (int i = 0; i < n;) {
            char c = *min_element(s.begin() + i, s.end());
            int mn = n - 1 - (find(s.rbegin(), s.rend(), c) - s.rbegin());
            for (char ch = '0'; ch <= c; ch++) {
                for (int j = 0; j < freq[ch - '0']; j++) {
                    answer.push_back(ch);
                }
                freq[ch - '0'] = 0;
            }
            for (int j = i; j <= mn; j++) {
                if (s[j] == c) {
                    answer.push_back(c);
                } else {
                    char new_c = min(s[j] + 1, int('9'));
                    freq[new_c - '0']++;
                }
            }
            i = mn + 1;
        }

        for (char ch = '0'; ch <= '9'; ch++) {
            for (int j = 0; j < freq[ch - '0']; j++) {
                answer.push_back(ch);
            }
            freq[ch - '0'] = 0;
        }

        cout << answer << '\n';
    }
    return 0;
}