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

bool isPrime(int x) {
    if (x == 1)
        return false;

    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0)
            return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        if (n % 2 == 0)
            cout << n / 2 << " " << n / 2 << "\n";
        else {
            if (isPrime(n))
                cout << n - 1 << " " << 1 << "\n";
            else {
                int mn = 0;
                for (int i = 2; i * i <= n; i++) {
                    if (n % i == 0) {
                        mn = i;
                        break;
                    }
                }

                mn = n / mn;
                cout << mn << " " << n - mn << "\n";
            }
        }
    }
    return 0;
}