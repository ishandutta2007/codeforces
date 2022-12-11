#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n + 1);
    int p = 0;
    for (int i = 2; i <= n; ++i) {
        if (a[i]) continue;
        ++p;
        for (int j = i; j <= n; j += i) {
            a[j] = p;
        }
    }
    for (int i = 2; i <= n; ++i) {
        cout << a[i] << ' ';
    }
}