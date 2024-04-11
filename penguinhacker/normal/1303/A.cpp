#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int current = 0;
        int ans = 0;
        int y = 0;
        for (int i=0; i<s.size(); ++i) {
            if (s[i] == '1') {
                if (y) {
                    ans += i-current-1;
                }
                y = 1;
                current = i;
            }
        }
        cout << ans << endl;
    }
    return 0;
}