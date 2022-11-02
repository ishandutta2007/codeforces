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
    int n;
    cin >> n;
    int a[n];
    for(int i = 0;i < n;i++) cin >> a[i];
    sort(a, a + n);
    cout << a[(n - 1) / 2];
}