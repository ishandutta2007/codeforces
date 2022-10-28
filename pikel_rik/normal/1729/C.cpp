#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        int n = (int) s.length();

        if (s.front() > s.back()) {
            for (auto &ch : s) {
                ch = 'a' + ('z' - ch);
            }
        }

        vector<int> answer;
        for (char c = s.front(); c <= s.back(); c++) {
            for (int i = 0; i < n; i++) {
                if (s[i] == c) {
                    answer.push_back(i);
                }
            }
        }

        cout << s.back() - s.front() << ' ' << (int) answer.size() << '\n';
        for (int position : answer) {
            cout << position + 1 << ' ';
        }
        cout << '\n';
    }
    return 0;
}