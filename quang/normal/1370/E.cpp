#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    int cnt[2] = {0, 0};
    int delta = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == t[i]) {
            continue;
        }
        if (s[i] == '1') {
            if (cnt[0] > 0) {
                cnt[0]--;
            }
            cnt[1]++;
            delta++;
        } else {
            if (cnt[1] > 0) {
                cnt[1]--;
            }
            cnt[0]++;
            delta--;
        }
    }
    if (delta != 0) {
        cout << -1 << endl;
        return 0;
    }
    cout << cnt[0] + cnt[1] << endl;
    return 0;
}