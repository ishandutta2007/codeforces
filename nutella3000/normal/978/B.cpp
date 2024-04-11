#include<bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    // online submission
#endif
    int n;
    string s;
    cin >> n >> s;
    s += 'W';
    int ans = 0, cnt = 0;
    for(int i = 0;i <= n;i++) {
        if (s[i] == 'x') cnt++;
        else {
            ans += max(0ll, cnt - 2);
            cnt = 0;
        }

    }
    cout << ans;
}