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
const int N = 51;

int n, k, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n, greater<>());

    for (int i = 0; i < n && k; i++) {
        cout << "1 " << a[i] << "\n";
        k -= 1;
    }

    for (int i = 0; i < n && k; i++) {
        for (int j = i + 1; j < n && k; j++) {
            cout << i + 2 << " ";
            for (int l = 0; l <= i; l++) cout << a[l] << " ";
            cout << a[j] << " ";
            cout << "\n";
            k -= 1;
        }
    }
    return 0;
}