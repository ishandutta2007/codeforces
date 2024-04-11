#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 1e6 + 5;

int n;
ll a[N];

ll f(ll x) {
    return (n * (2 * x + 1 - n)) / 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    ll lo = n - 1, hi = a[n - 1];
    ll sum = accumulate(a, a + n, 0ll);

    while (lo < hi) {
        ll mid = lo + (hi - lo + 1) / 2;
        if (f(mid) <= sum)
            lo = mid;
        else hi = mid - 1;
    }

    sum -= f(lo);

    for (int i = n - 1; i >= 0; i--) {
        a[i] = lo--;
    }

    for (int i = 0; i < n; i++) {
        if (!sum)
            break;
        a[i]++;
        sum--;
    }

    for (int i = 0; i < n; i++)
        cout << a[i] << " \n"[i + 1 == n];

//    bool flag = false;
//
//    for (int i = 1; i < n; i++) {
//        flag |= a[i] - a[i - 1] >= 2;
//    }
//
//    while (flag) {
//        vector<int> add(n);
//        for (int i = 1; i < n; i++) {
//            if (a[i] - a[i - 1] >= 2)
//                add[i]--, add[i - 1]++;
//        }
//
//        for (int i = 0; i < n; i++)
//            a[i] += add[i];
//
//        flag = false;
//
//        for (int i = 1; i < n; i++) {
//            flag |= a[i] - a[i - 1] >= 2;
//        }
//    }
//
//    for (int i = 0; i < n; i++)
//        cout << a[i] << " ";
    return 0;
}