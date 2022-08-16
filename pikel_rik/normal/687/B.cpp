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
const int N = 1e6 + 5;

int n, k, a[N];
bool ok[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i], ok[a[i]] = true;

    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j += i) {
            ok[i] |= ok[j];
        }
    }

    bool ans = true;
    int temp = k;

    for (int i = 2; i * i <= temp; i++) {
        if (temp % i == 0) {
            int p = 1;
            while (temp % i == 0) {
                p *= i;
                temp /= i;
            }
            ans &= ok[p];
        }
    }

    if (temp > 1)
        ans &= ok[temp];
    ans |= ok[k];

    cout << (ans ? "YES\n" : "NO\n");
    return 0;
}