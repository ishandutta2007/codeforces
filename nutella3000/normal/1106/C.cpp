#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int a[n];
    for(int i = 0;i < n;i++) cin >> a[i];
    sort(a,a + n);
    ll ans = 0;
    int i1 = n - 1;
    for(int i = 0;i < n;i++) {
        if (i > i1) break;
        ll u = a[i] + a[i1];
        i1--;
        ans += u * u;
    }
    cout << ans;
}