#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 1e5 + 5;

int n, a[N];

bool f(int l) {
    multiset<int> s;

    for (int i = 0; i < l; i++) {
        s.insert(a[i]);
    }

    int c = 0;
    if (*s.begin() >= *s.rbegin() - 1)
        return true;

    for (int i = 1; i + l - 1 < n; i++) {
        s.erase(s.find(a[i-1]));
        s.insert(a[i + l - 1]);

        if (*s.begin() >= *s.rbegin() - 1)
            return true;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    int lo = 1, hi = n;

    while (lo < hi) {
        int mid = lo + (hi - lo + 1) / 2;
        if (f(mid))
            lo = mid;
        else hi = mid - 1;
    }

    cout << lo << "\n";
    return 0;
}