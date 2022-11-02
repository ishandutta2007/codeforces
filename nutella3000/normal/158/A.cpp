#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n,k;
    cin >> n >> k;
    int a[n];
    for(int i = 0;i < n;i++) cin >> a[i];
    sort(a,a + n);
    int ans = 0;
    for(int i = n - 1;i >= 0;i--) {
        if (a[i] >= a[n - k] && a[i] > 0) ans++;
    }
    cout << ans;
}