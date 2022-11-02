#include <bits/stdc++.h>
using namespace std;

#define long long long
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int i = 0;i < n;i++) cin >> a[i];
    long b[n];
    b[n - 1] = a[n - 1];
    for(int i = n - 2;i >= 0;i--) b[i] = a[i] + b[i + 1];
    long ans = b[0];
    b[0] = -1e12;
    sort(b, b + n);
    for(int i = n - 1;i > n - k;i--) ans += b[i];
    cout << ans;
}