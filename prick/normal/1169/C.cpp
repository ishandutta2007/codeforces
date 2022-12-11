#include <bits/stdc++.h>

using namespace std;

bool check(int n, int m, vector<int> a, int k) {
    if (a[0] + k >= m) {
        a[0] = 0;
    }
    for (int i = 1; i < n; ++i) {
        if (a[i] < a[i - 1]) {
            if (a[i] + k < a[i - 1]) {
                return false;
            }
            a[i] = a[i - 1];
        } else {
            if (a[i] - m + k >= a[i - 1]) {
                a[i] = a[i - 1];
            }
        }
    }
    return true;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    int left = -1, right = m;
    while (right - left > 1) {
        int mid = (left + right) / 2;
        if (check(n, m, a, mid)) {
            right = mid;
        } else {
            left = mid;
        }
    }
    cout << right << '\n';
}