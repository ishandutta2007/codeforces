#include<bits/stdc++.h>

using namespace std;
#define int long long
const int max_n = 104;
bool used[max_n];
signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    // online submission
#endif
    int t;
    cin >> t;
    while(t--) {
        int a;
        cin >> a;
        cout << (a + 6) / 7 << '\n';
    }
}