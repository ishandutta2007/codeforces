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
    vector<int> ans;
    int cnt = 0;
    for(int i = 0;i <= n;i++) {
        if (s[i] == 'B') cnt++;
        else{
            if (cnt != 0) ans.emplace_back(cnt);
            cnt = 0;
        }
    }
    cout << ans.size() << '\n';
    for(int i : ans) cout << i << " ";
}