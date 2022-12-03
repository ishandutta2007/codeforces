#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> f(2);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        f[a[i] & 1] |= 1;
    }
    if (f[0] && f[1]) {
        sort(a.begin(), a.end());    
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    return 0;
}