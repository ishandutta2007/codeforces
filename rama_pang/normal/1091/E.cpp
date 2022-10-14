#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<int> d(n), in;
    lint odd = 0;
    for (int i = 0; i < n; i++) {
        cin >> d[i];
        odd += d[i];
    }
    sort(begin(d), end(d));
    in = d;
    n++;
    odd %= 2;

    auto check = [&](int m) { // ErdsGallai theorem
        d = in;
        d.emplace_back(m);
        sort(begin(d), end(d));
        vector<lint> pref(n + 1);
        int pos = 0;
        for (int i = 0; i < n; i++) {
            if (d[i] == m) {
                pos = n - i;
            }
        }
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + d[i];
        }
        for (int k = 1, j = 0; k <= n; k++) {
            lint L = pref[n] - pref[n - k];
            lint R = 1ll * k * (k - 1);
            while (j < n && d[j] < k) {
                j++;
            }
            int plus = min(n - k, j);
            R += pref[plus] + 1ll * k * (n - k - plus);
            // cout << L << " " << R << "\n";
            if (L <= R) {
                continue;
            }
            if (k < pos) {
                return -1; // too high
            } else {
                return 1; // too low
            }
        }
        return 0; // valid
    };

    int l = 0, r = n / 2;
    int low = -1, high = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        int mdd = mid * 2 + odd;
        int c = check(mdd);
        if (c == 0) {
            low = mdd;
            r = mid - 1;
        } else if (c == 1) {
            r = mid - 1;
        } else if (c == -1) {
            l = mid + 1;
        }
    }

    l = 0, r = n / 2;
    while (l <= r) {
        int mid = (l + r) / 2;
        int mdd = mid * 2 + odd;
        int c = check(mdd);
        if (c == 0) {
            high = mdd;
            l = mid + 1;
        } else if (c == 1) {
            r = mid - 1;
        } else if (c == -1) {
            l = mid + 1;
        }
    }
    if (low > high || low == -1 || high == -1) {
        cout << -1 << "\n";
        return 0;
    }
    for (int i = low; i <= high; i += 2) {
        if (i > low) {
            cout << " ";
        }
        cout << i;
    }
    cout << "\n";
    return 0;
}