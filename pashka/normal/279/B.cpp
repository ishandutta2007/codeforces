#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

    int n, t;
    cin >> n >> t;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int l = 0;
    int s = 0;
    int res = 0;
    for (int r = 0; r < n; r++) {
        s += a[r];
        while (s > t) {
            s -= a[l];
            l++;
        }
        res = max(res, r - l + 1);
    }
    cout << res << "\n";

}