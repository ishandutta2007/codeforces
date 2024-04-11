#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;
    if (k <= n) {
        cout << (k - 1) / 2 << endl;
        return 0;
    }
    if (n + n - 1 < k) {
        cout << 0 << endl;
        return 0;
    }
    long long pos = (k - 1) / 2;
    long long pos1 = k - pos;
    long long low = -1ll, high = 1e15;
    while (high - low > 1) {
        long long mid = (low + high) >> 1ll;
        long long x = pos - mid;
        long long y = pos1 + mid;
        int f = 0;
        if (x <= 0) f = 1;
        if (y > n) f = 1;
        // if (mid == 1) {
        //     cout << x << " " << y << endl;
        // }
        if (!f) {
            low = mid;
        } else {
            high = mid;
        }
    }
    // cout << pos << endl;
    cout << low + 1 << endl;
    return 0;
}