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

int p;

int modexp(int x, int n) {
    if (n == 0)
        return 1;
    int ans = modexp(x * x % p, n / 2);
    if (n % 2) return x * ans % p;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> p;

    int c = 0;
    for (int i = 1; i < p; i++) {
        bool flag = false;

        for (int j = 1; j < p - 1; j++) {
            flag |= (modexp(i, j) == 1);
        }

        if (!flag and modexp(i, p - 1) == 1)
            c += 1;
    }

    cout << c << "\n";
    return 0;
}