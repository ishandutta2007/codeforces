#include <bits/stdc++.h>

using namespace std;

const int N = 1111;

string mask;
string s[N];

int n, m;

int main() {
    cin >> n;
    cin >> mask;
    set<char> guessed;
    for (char c : mask) if (c != '*') guessed.insert(c);
    cin >> m;
    vector<string> relevant;
    for (int i = 1; i <= m; ++i) {
        cin >> s[i];
        bool correct = true;
        for (int j = 0; j < s[i].size(); ++j) {
            if (guessed.count(s[i][j])) {
                if (mask[j] == '*') {
                    correct = false;
                    break;
                } else {
                    if (mask[j] != s[i][j]) {
                        correct = false;
                        break;
                    }
                }
            }
            if (!guessed.count(s[i][j]) && mask[j] != '*') {
                correct = false;
                break;
            }
        }
        if (correct) {
            relevant.push_back(s[i]);
        }
    }
    int ans = 0;
    for (char c = 'a'; c <= 'z'; ++c) if (!guessed.count(c)) {
        bool ok = true;
        for (string &st : relevant) {
            bool cur_ok = false;
            for (int i = 0; i < st.size(); ++i) {
                if (st[i] == c && mask[i] == '*') {
                    cur_ok = true;
                    break;
                }
            }
            if (!cur_ok) {
                ok = false;
            }
        }
        if (ok) {
            ans += 1;
        }
    }
    cout << ans << endl;
    return 0;
}