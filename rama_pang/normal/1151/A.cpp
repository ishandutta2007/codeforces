#include <bits/stdc++.h>
using namespace std;
using lint = long long;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N;
    string s;
    cin >> N >> s;
    string t = "ACTG";
    int ans = 1e5;
    for (int i = 0; i + 3 < s.size(); i++) {
        int dist = 0;
        for (int j = i; j < i + 4; j++) {
            int k = min(abs(s[j] - t[j - i]), abs(-s[j] + 26 + t[j - i]));
            if (k >= 13) {
                dist += 26 - k;
            } else {
                dist += k;
            }
        }
        ans = min(ans, dist);
    }
    cout << ans << "\n";

}