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
    string ans;
    int cnt = 1;
    int now = 0;
    for(int i = 0;i < s.size();i++) {
        now++;
        if (now == cnt) {
            now = 0;
            cnt++;
            ans += s[i];
        }
    }
    cout << ans;
}