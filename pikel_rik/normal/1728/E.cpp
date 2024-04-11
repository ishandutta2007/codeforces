#include <bits/stdc++.h>
using namespace std;

template<typename T>
std::tuple<T, long long, long long> ext_euclid(T a, T b) {
    long long x = 1, y = 0, x1 = 0, y1 = 1;
    while (a != 0) {
        T q = b / a;
        std::tie(x, x1) = std::make_pair(-q * x + x1, x);
        std::tie(y, y1) = std::make_pair(-q * y + y1, y);
        std::tie(a, b) = std::make_pair(-q * a + b, a);
    }
    if (b < 0) {
        b = -b, x1 = -x1, y1 = -y1;
    }
    return std::make_tuple(b, x1, y1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    constexpr long long inf = 1e18;

    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    vector<long long> d(n);
    for (int i = 0; i < n; i++) {
        d[i] = a[i] - b[i];
    }

    long long sum_a = accumulate(a.begin(), a.end(), 0ll);
    long long sum_b = accumulate(b.begin(), b.end(), 0ll);

    sort(d.rbegin(), d.rend());
    partial_sum(d.begin(), d.end(), d.begin());

    long long mx = *max_element(d.begin(), d.end());
    int first_mx = find(d.begin(), d.end(), mx) - d.begin();
    int last_mx = n - (find(d.rbegin(), d.rend(), mx) - d.rbegin()) - 1;

    int m;
    cin >> m;

    auto first_binary_search = [&](auto g, auto x, auto xj, auto y, auto yj, auto bound) -> int {
        auto l = xj * yj / g;
        long long lo = -(inf / l), hi = inf / l;
        while (lo < hi) {
            long long mid = lo + (hi - lo + 1) / 2;
            if (xj * (x + mid * (yj / g)) <= bound) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        if (xj * (x + lo * (yj / g)) >= 0) {
            return xj * (x + lo * (yj / g));
        } else {
            return -1;
        }
    };

    auto second_binary_search = [&](auto g, auto x, auto xj, auto y, auto yj, auto bound) -> int {
        auto l = xj * yj / g;
        long long lo = -(inf / l), hi = inf / l;
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (xj * (x + mid * (yj / g)) >= bound) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        if (xj * (x + lo * (yj / g)) <= n) {
            return xj * (x + lo * (yj / g));
        } else {
            return -1;
        }
    };

    while (m--) {
        long long xj, yj;
        cin >> xj >> yj;

        auto [g, x, y] = ext_euclid(xj, yj);
        if (n % g != 0) {
            cout << "-1\n";
            continue;
        }

        x *= n / g;
        y *= n / g;

        // find largest legal x * xj s.t. x * xj <= last_mx + 1
        // find smallest legal x * xj s.t. x * xj >= first_mx + 1

        int i = -1, j = -1;
        if (mx > 0) {
            i = first_binary_search(g, x, xj, y, yj, last_mx + 1);
            j = second_binary_search(g, x, xj, y, yj, first_mx + 1);
        } else {
            i = second_binary_search(g, x, xj, y, yj, 0);
        }

        if (i == -1 && j == -1) {
            cout << "-1\n";
        } else {
            long long ans = 0;
            if (i != -1) {
                ans = max(ans, (i == 0 ? 0 : d[i - 1]) + sum_b);
            }
            if (j != -1) {
                ans = max(ans, (j == 0 ? 0 : d[j - 1]) + sum_b);
            }
            cout << ans << '\n';
        }
    }
    return 0;
}