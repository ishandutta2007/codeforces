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
const int N = 1e5 + 5;

int n, a[N], bit[20][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    unordered_set<int> s1, s2, ans;

    for (int i = 0; i < n; i++) {
        s2.clear();
        for (int x : s1)
            s2.insert(a[i] | x);

        s2.insert(a[i]);
        for (int x : s2)
            ans.insert(x);

        s1 = s2;
    }

    cout << ans.size() << "\n";
    return 0;
}