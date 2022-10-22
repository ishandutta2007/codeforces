#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (ll& i : a)
        cin >> i;
    for (ll& i : b)
        cin >> i;
    for (int i=1; i<n; ++i) {
        a[i]=max(a[i]+b[i-1], a[i-1]);
        b[i]=max(b[i-1], b[i]+a[i-1]);
    }
    cout << max(a.back(), b.back());
    return 0;
}