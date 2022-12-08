#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> A(n), B(n);
    for (int i = 0; i < n; ++i) cin >> A[i] >> B[i];

    int ans = 0;
    unordered_set<string> used;
    for (int time = 0; ; ++time) {
        if (used.find(s) != used.end() && time >= 5 * 5 * 5 * 5 * 4 * 3 * 2) {
            break;
        }
        ans = max(ans, count(s.begin(), s.end(), '1'));
        used.insert(s);
        for (int j = 0; j < n; ++j) {
            if (time >= B[j] && (time - B[j]) % A[j] == 0) {
                s[j] = (s[j] == '0' ? '1' : '0');
            }
        }
    }
    cout << ans << "\n";
    return 0;
}