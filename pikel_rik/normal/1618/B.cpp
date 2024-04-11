#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<string> bigrams(n - 2);
        for (auto &bigram : bigrams) {
            cin >> bigram;
        }

        for (int i = 0; i + 1 < n - 2; i++) {
            if (bigrams[i][1] != bigrams[i + 1][0]) {
                bigrams.insert(bigrams.begin() + i + 1, string(1, bigrams[i][1]) + bigrams[i + 1][0]);
                break;
            }
        }

        if (bigrams.size() != n - 1) {
            bigrams.push_back(string(1, bigrams.back()[1]) + 'a');
        }

        string s(1, bigrams.front()[0]);
        for (int i = 0; i < n - 1; i++) {
            s += bigrams[i][1];
        }
        cout << s << '\n';
    }
    return 0;
}