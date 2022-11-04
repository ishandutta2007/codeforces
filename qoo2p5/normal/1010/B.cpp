#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = (int) (1e9 + 1e6 + 123);
const ll LINF = (long long) (1e18 + 1e9 + 123);

template<class A, class B> bool mini(A &x, const B &y) {
    if (y < x) {
        x = y;
        return true;
    }
    return false;
}

template<class A, class B> bool maxi(A &x, const B &y) {
    if (y < x) {
        x = y;
        return true;
    }
    return false;
}

#define int long long

int ask(int y) {
    cout << y << endl;
    cin >> y;
    if (y == -2) {
        exit(0);
    }
    if (y == 0) {
        exit(0);
    }
    return y;
}

signed main() {
    /*ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(10);*/

    int m, n;
    vector<bool> inv(n);
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        if (ask(m) != -1) {
            inv[i] = true;
        }
    }

    int left = 0;
    int right = m + 1;
    int iter = 0;
    while (right - left > 1) {
        int mid = (left + right) / 2;
        int res = ask(mid);
        if (inv[iter]) {
            res = -res;
        }
        if (res == -1) {
            right = mid;
        } else {
            left = mid;
        }
        iter = (iter + 1) % n;
    }

    assert(false);

    return 0;
}