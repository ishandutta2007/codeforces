#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int T;
    cin >> T;
    while (T--) {
        int n;
        string s;
        cin >> n >> s;
        int cnt = 0;
        bool angry = false;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'A') {
                ans = max(ans, cnt);
                cnt = 0;
                angry = true;
            }
            if (angry && s[i] == 'P') {
                cnt++;
            }
        }
        ans = max(ans, cnt);

        cout << ans << "\n";
    }


}