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

int n, m, a[N];

bool f(ll t) {
    vector<int> temp(a, a + n + 1);

    int ptr = n;
    for (int i = 1; i <= m && ptr; i++) {
        while (!temp[ptr] and ptr)
            ptr--;
        if (temp[ptr]) {
            ll cur = t - ptr;
            while (cur > 0 and ptr) {
                if (cur >= temp[ptr])
                    cur -= temp[ptr], temp[ptr] = 0, ptr--;
                else temp[ptr] -= cur, cur = 0;
            }
        }
    }

//    cout << t << "\n";
//    for (int i : temp) cout << i << " ";
//    cout << "\n";

    for (int i : temp) {
        if (i) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];

    ll lo = 1, hi = 1e15;

    while (lo < hi) {
        ll mid = lo + (hi - lo) / 2;

        if (f(mid))
            hi = mid;
        else lo = mid + 1;
    }

    cout << lo << "\n";
//    cout << f(5);
    return 0;
}