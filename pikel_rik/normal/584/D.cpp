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

    int n;
    cin >> n;

    int left_over = 0;
    for (int i = n; i >= 0; i -= 2) {
        if (isPrime(i)) {
            left_over = n - i;
            break;
        }
    }

    if (left_over == 0) {
        cout << 1 << "\n";
        cout << n << "\n";
        return 0;
    }

    if (isPrime(left_over)) {
        cout << 2 << "\n";
        cout << n - left_over << " " << left_over << "\n";
        return 0;
    }

    for (int i = 2; i <= left_over - 2; i++) {
        if (isPrime(i) and isPrime(left_over - i)) {
            cout << 3 << "\n";
            cout << n - left_over << " " << i << " " << left_over - i << "\n";
            return 0;
        }
    }
    return 0;
}