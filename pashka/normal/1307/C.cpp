#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int n = s.size();
    vector<long> cnt(26);
    vector<vector<long>> res(26, vector<long>(26));
    for (int i = n - 1; i >= 0; i--) {
        int c = s[i] - 'a';
        for (int x = 0; x < 26; x++) {
            res[c][x] += cnt[x];
        }
        cnt[c]++;
    }
    long ans = 0;
    for (int i = 0; i < 26; i++) {
        ans = max(ans, cnt[i]);
        for (int j = 0; j < 26; j++) {
            ans = max(ans, res[i][j]);
        }
    }
    cout << ans << "\n";

    return 0;
}