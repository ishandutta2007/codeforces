#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ordered_set = tree<int, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 1e5 + 1;

int n;
pair<int, int> a[2*N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n; n *= 2;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i % (n / 2) + 1;
    }
    cin >> mod;

    sort(a, a + n);

    int c = 1, c1 = 0, ans = 1;
    for (int i = 1; i < n; i++) {
        if (a[i].first != a[i-1].first) {
            int num = 1;
            for (int j = 1; j <= c; j++) {
                int k = j;
                while (j % 2 == 0 and c1) {
                    j /= 2;
                    c1 -= 1;
                }
                num = (num * (ll)j) % mod;
                j = k;
            }
            ans = (ans * (ll)num) % mod;
            c = 1; c1 = 0;
        }
        else {
            c += 1;
            if (a[i].second == a[i-1].second)
                c1 += 1;
        }
    }

    if (c > 1) {
        int num = 1;
        for (int j = 1; j <= c; j++) {
            int k = j;
            while (j % 2 == 0 and c1) {
                j /= 2;
                c1 -= 1;
            }
            num = (num * (ll)j) % mod;
            j = k;
        }
        ans = (ans * (ll)num) % mod;
    }

    cout << ans << "\n";
    return 0;
}