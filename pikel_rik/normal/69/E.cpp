#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 9;
const int inf = 2e9 + 5;
const int N = 1e5 + 5;

int n, k, a[N];

struct comp {
    bool operator() (const pair<int, int> &p1, const pair<int, int> &p2) {
        if (p1.second != p2.second)
            return p1.second < p2.second;
        return p1.first > p2.first;
    }
};

set<pair<int, int>, comp> s;
map<int, int> m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < k; i++) {
        s.erase({a[i], m[a[i]]});
        m[a[i]] += 1;
        s.insert({a[i], m[a[i]]});
    }

    if ((*s.begin()).second == 1)
        cout << (*s.begin()).first << "\n";
    else cout << "Nothing\n";

    for (int i = 1; i + k - 1 < n; i++) {
        s.erase({a[i-1], m[a[i-1]]});
        m[a[i-1]] -= 1;
        if (m[a[i-1]] > 0)
            s.insert({a[i-1], m[a[i-1]]});

        s.erase({a[i + k - 1], m[a[i + k - 1]]});
        m[a[i + k - 1]] += 1;
        s.insert({a[i + k - 1], m[a[i + k - 1]]});

        if ((*s.begin()).second == 1)
            cout << (*s.begin()).first << "\n";
        else cout << "Nothing\n";
    }
    return 0;
}