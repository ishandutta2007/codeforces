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
const int N = 1e6 + 5;

int n, p, a[N];

int modexp(int x, int n) {
    int ans = 1;
    while (n > 0) {
        if (n % 2 != 0) ans = ans * (ll)x % mod;
        x = x * (ll)x % mod;
        n /= 2;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        cin >> n >> p;
        for (int i = 0; i < n; i++) cin >> a[i];

        if (n == 1) {
            cout << modexp(p, a[0]) << "\n";
            continue;
        }

        if (p == 1) {
            cout << n % 2 << "\n";
            continue;
        }

        sort(a, a + n);
        map<int, int, greater<>> s1, s2;

        s1[a[n-1]]++;
        s2[a[n-2]]++;
        for (int i = n - 3; i >= 0; i--) {
            while (!s1.empty() and !s2.empty() and *s1.begin() == *s2.begin()) {
                s1.erase(s1.begin());
                s2.erase(s2.begin());
            }

            if (s1.empty()) {
                s1[a[i]]++;
                continue;
            }

            if (s2.empty()) {
                s2[a[i]]++;
                continue;
            }

            if (*s1.begin() < *s2.begin()) {
                s1[a[i]]++;
                while (s1[a[i]] == p) {
                    s1.erase(a[i]);
                    a[i]++;
                    s1[a[i]]++;
                }
            }
            else if (*s2.begin() < *s1.begin()) {
                s2[a[i]]++;
                while (s2[a[i]] == p) {
                    s2.erase(a[i]);
                    a[i]++;
                    s2[a[i]]++;
                }
            }
        }

        int sum1 = 0, sum2 = 0;
        for (auto pa : s1)
            sum1 = (sum1 + pa.second * (ll)modexp(p, pa.first)) % mod;

        for (auto pa : s2)
            sum2 = (sum2 + pa.second * (ll)modexp(p, pa.first)) % mod;

        cout << ((sum1 - sum2) % mod + mod) % mod << "\n";
    }
    return 0;
}