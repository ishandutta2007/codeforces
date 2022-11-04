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

const int N = (int) 1e5 + 123;

int n;
ld a[N], b[N];

ld f(ld mass, ld coef) {
    return mass / coef;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(10);

    cin >> n;
    ld m;
    cin >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    a[n] = a[0], b[n] = b[0];

    ld left = 0;
    ld right = INF;
    for (int iter = 0; iter < 100; iter++) {
        ld mid = (left + right) / 2;
        ld have = mid;
        bool ok = true;

        for (int i = 0; i < n; i++) {
            if (f(m + have, a[i]) > have) {
                ok = false;
                break;
            }
            have -= f(m + have, a[i]);
            if (f(m + have, b[i + 1]) > have) {
                ok = false;
                break;
            }
            have -= f(m + have, b[i + 1]);
        }

        if (ok) {
            right = mid;
        } else {
            left = mid;
        }
    }

    if (left > 1e9) {
        cout << "-1\n";
        return 0;
    }
    cout << left << "\n";

    return 0;
}