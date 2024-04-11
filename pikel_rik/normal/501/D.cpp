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
const int N = 2e5 + 5;

int n, a[N], b[N], num1[N], num2[N], num3[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    ordered_set<int> s;
    for (int i = 0; i < n; i++) s.insert(i);

    for (int i = 0; i < n; i++) {
        num1[n - i - 1] = s.order_of_key(a[i]);
        s.erase(a[i]);
    }

    for (int i = 0; i < n; i++) s.insert(i);

    for (int i = 0; i < n; i++) {
        num2[n - i - 1] = s.order_of_key(b[i]);
        s.erase(b[i]);
    }

    int carry = 0;
    for (int i = 0; i < n; i++) s.insert(i);

    for (int i = 0; i < n; i++) {
        int val = num1[i] + num2[i] + carry;
        num3[i] = val % (i + 1);
        carry = val / (i + 1);
    }

    for (int i = n - 1; i >= 0; i--) {
        num3[i] = *s.find_by_order(num3[i]);
        s.erase(num3[i]);
    }

    for (int i = n - 1; i >= 0; i--) cout << num3[i] << " "; cout << "\n";
    return 0;
}