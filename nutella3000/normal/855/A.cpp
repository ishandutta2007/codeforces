#include<bits/stdc++.h>

using namespace std;
#define int long long
const int max_n = 104;
bool x[11];

signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    // online submission
#endif
    int n;
    cin >> n;
    set<string> a;
    for(int i = 0;i < n;i++) {
        string s;
        cin >> s;
        if (a.find(s) == a.end()) cout << "NO" << '\n';
        else cout << "YES" << '\n';
        a.emplace(s);
    }
}