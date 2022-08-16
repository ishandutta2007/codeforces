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

int f(ll x) {
    if (x < 0)
        return -f(-x);
    int sum = 0;
    while (x) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

ll construct (int sum) {
    ll num = 0;
    num = sum % 9;

    sum -= sum % 9;
    while (sum) {
        num = 10 * num + 9;
        sum -= 9;
    }

    return num;
}

ll power(ll x, ll n) {
    ll ans = 1;
    for (int i = 0; i < n; i++)
        ans *= x;
    return ans;
}

ll nine(int n) {
    ll ans = 0;
    while (n--)
        ans = ans * 10 + 9;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a = {{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9}};

        ll best = (ll)1e18;
        for (int i = 0; i < 18; i++) {
            for (int j = 0; j <= a.size() / 2; j++) {
                int sum = 0;
                for (int i1 = 0; i1 < k + 1; i1++) {
                    sum += a[j + i1];
                    if (j + i1 > 9)
                        sum += -9 * i;
                }

                if (n >= sum and (n - sum) % (k + 1) == 0) {
                    int temp = n;
                    temp -= sum;
                    temp /= (k + 1);

                    temp -= i * 9;
                    ll num = nine(i);
                    if (temp < 0)
                        continue;

                    if (temp <= 8) {
                        num = temp * power(10, i) + num;
                        temp = 0;
                    }
                    else {
                        num = 8 * power(10, i) + num;
                        temp -= 8;
                    }

                    num = power(10, i + 1) * construct(temp) + num;
                    num = 10 * num + j;

                    temp = 0;
                    for (int som = 0; som < k + 1; som++) {
                        temp += f(num + som);
                    }
                    if (temp == n)
                        best = min(best, num);
                }
            }
        }

        if (best == (ll)1e18)
            cout << "-1\n";
        else cout << best << "\n";
    }
    return 0;
}