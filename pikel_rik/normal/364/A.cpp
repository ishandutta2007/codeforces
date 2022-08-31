#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 4e3 + 5;

int n, s, a[N], cnt[9*N];
string str;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> s >> str;
    n = str.length();

    int c = 0;
    for (int i = 0; i < n; i++) {
        bool flag = false;
        for (int j = i; j < n; j++) {
            flag |= (str[j] != '0');
            if (!flag)
                c++;
        }
    }

    for (int i = 1; i <= n; i++) {
        a[i] = str[i - 1] - '0';
        a[i] += a[i-1];

        for (int j = 1; j <= i; j++) {
            cnt[a[i] - a[j-1]]++;
        }
    }

    ll ans = 0;

    if (s == 0) {
        ans = c * (ll)n * (n + 1) - c * (ll)c;
        cout << ans << "\n";
        return 0;
    }

    for (int i = 1; i * i <= s; i++) {
        if (s % i == 0) {
            if (i <= 9 * 4000 and s / i <= 9 * 4000) {
                ans += cnt[s / i] * (ll)cnt[i];
                if (s / i != i)
                    ans += cnt[s / i] * (ll)cnt[i];
            }
        }
    }

    cout << ans << "\n";
    return 0;
}