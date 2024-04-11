#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template<typename A, typename B> bool mini(A &x, const B &y) {
    if (y < x) {
        x = y;
        return true;
    }
    return false;
}

template<typename A, typename B> bool maxi(A &x, const B &y) {
    if (y > x) {
        x = y;
        return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int &x : a) {
        cin >> x;
    }
    sort(a.begin(), a.end());

    int cur = a[n / 2];
    ll ans = 0;
    if (cur >= s) {
        for (int i = 0; i <= n / 2; i++) {
            if (a[i] > s) {
                ans += a[i] - s;
            }
        }
    } else {
        for (int i = n / 2; i < n; i++) {
            if (a[i] < s) {
                ans += s - a[i];
            }

        }
    }

    cout << ans << "\n";

    return 0;
}