#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int N = s.size();
        s.push_back('?');
        s.insert(s.begin(), '?');
        for (int i = 1; i <= N; i++) {
            if (s[i] == '?') {
                for (char j = 'a'; j <= 'c'; j++) {
                    if (s[i - 1] != j && s[i + 1] != j) {
                        s[i] = j;
                        break;
                    }
                }
            }
        }

        for (int i = 1; i <= N; i++) {
            if (s[i] == '?') {
                s = "?-1?";
                break;
            }
            if (s[i] == s[i + 1]) {
                s = "?-1?";
                break;
            }
        }

        cout << string(s.begin() + 1, s.end() - 1) << "\n";

    }
}