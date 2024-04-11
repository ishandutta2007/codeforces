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
    int n, k;
    cin >> n >> k;
    cout << (2 * n + k - 1) / k + (5 * n + k - 1) / k + (8 * n + k - 1) / k;
}