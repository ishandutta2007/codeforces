#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = INT_MAX;

int b, d, n, m;
string a, c;

vector<pair<int, int>> rep;
pair<int, int> crit;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> b >> d >> a >> c;
    n = a.length();
    m = c.length();

    if (m * d > n * b) {
        cout << "0\n";
        return 0;
    }

    int ptr = 0, cnt = 0;
    while (rep.size() <= n and cnt <= 10000) {
        for (int i = 0; i < n; i++) {
            if (a[i] == c[ptr]) {
                ptr++;
                if (ptr == m) {
                    ptr = 0;
                    rep.emplace_back(cnt, i);
                }
            }
        }
        cnt++;
    }

    if (rep.empty()) {
        cout << "0\n";
        return 0;
    }

    int start = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (rep[i].second == rep[j].second) {
                crit = {i - j, rep[i].first - rep[j].first};
                start = j;
                break;
            }
        }
        if (crit.first != 0)
            break;
    }

    int left = n * b;

    left -= rep[start].first * n + rep[start].second + 1;
    if (left < 0) {
        cout << "0\n";
        return 0;
    }

    int lo = 0, hi = 1e9;

    while (lo < hi) {
        int mid = lo + (hi - lo + 1) / 2;
        ld val = mid * (ld)crit.second * (ld)n;
        if (val > 1e10)
            hi = mid - 1;
        else {
            if (left - mid * (ll)crit.second * n < 0)
                hi = mid - 1;
            else lo = mid;
        }
    }

    ll ans = start + 1 + crit.first * (ll)lo;
    left -= lo * crit.second * n;

    int ans2 = -1;
    for (int i = start + 1; i <= start + crit.first; i++) {
        if (left - (rep[i].first * n + rep[i].second + 1 - rep[start].first * n - rep[start].second - 1) < 0) {
            ans2 = i - 1;
            break;
        }
    }

    ans2 = ans2 - start;
    ans += ans2;

    cout << ans / d << "\n";
    return 0;
}