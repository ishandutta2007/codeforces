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
const int N = 1e5 + 5;

int n, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    int temp = n;
    vector<int> div;

    for (int i = 1; i * i <= temp; i++) {
        if (temp % i == 0) {
            div.push_back(i);
            if (i != n / i)
                div.push_back(n / i);
        }
    }

    for (int x : div) {
        if (n / x <= 2)
            continue;
        for (int i = 0; i < x; i++) {
            int sum = 0;
            for (int j = i; j < n; j += x) {
                sum += a[j];
            }
            if (sum == n / x) {
                cout << "YES\n";
                return 0;
            }
        }
    }

    cout << "NO\n";
    return 0;
}