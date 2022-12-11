#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n);
    bool odd = false;
    bool even = false;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] % 2 == 0) even = true;
        else odd = true;
    }
    if (odd && even) {
        sort(begin(a), end(a));
    }
    for (auto i: a) {
        cout << i << ' ';
    }
}