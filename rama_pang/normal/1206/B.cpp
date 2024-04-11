#include <bits/stdc++.h>
using namespace std;
using lint = long long;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    int pos = 0, neg = 0, zer = 0;
    lint ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > 0) {
            pos++;
            ans += a[i] - 1;
        }
        if (a[i] < 0) {
            neg++;
            ans += abs(a[i]) - 1;
        }
        if (a[i] == 0) {
            zer++;
        }
    }

    if (neg % 2 == 0) {
        ans += zer;
    } else {
        if (zer > 0) {
            ans += zer;
        } else {
            ans += 2;
        }
    }
    cout << ans << "\n";
    return 0;
}