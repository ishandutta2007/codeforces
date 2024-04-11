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
    int a;
    cin >> a;
    if (a % 4 == 2) {
        cout << 1 << " B";
    }else cout << (5 - a % 4) % 4 << " A";
}