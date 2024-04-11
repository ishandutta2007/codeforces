#include<bits/stdc++.h>

using namespace std;
#define int long long
const int max_n = 104;


signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    // online submission
#endif
    int n, m;
    string s;
    cin >> n >> m >> s;
    while(m--) {
        int l, r;
        char o1, o2;
        cin >> l >> r >> o1 >> o2;
        for(int i = l - 1;i < r;i++) {
            if (s[i] == o1) s[i] = o2;
        }
    }
    cout << s;
}