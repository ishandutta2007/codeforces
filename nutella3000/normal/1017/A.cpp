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
    int n, a[4], tom = 0;
    cin >> n;
    for(int i = 0;i < 4;i++) {
        cin >> a[i];
        tom += a[i];
    }
    int ans = 1;
    for(int i = 0;i < n - 1;i++) {
        int sum = 0;
        for(int j = 0;j < 4;j++) {
            cin >> a[j];
            sum += a[j];
        }
        if (sum > tom) ans++;
    }
    cout << ans;
}