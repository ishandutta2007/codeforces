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

set<int> s;
map<int, int> cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int q;
    cin >> q;

    s.insert(0);

    while (q--) {
        char ch;
        cin >> ch;

        int x;
        cin >> x;

        if (ch == '+') {
            cnt[x]++;
            if (cnt[x] == 1)
                s.insert(x);
        }
        else if (ch == '-') {
            cnt[x]--;
            if (cnt[x] == 0)
                s.erase(x);
        }
        else {
            int y = ~x;
            int l = 0, r = UINT_MAX;

            for (int p = 31; p >= 0; p--) {
                if (y & (1 << p)) {
                    auto it = s.lower_bound(l | (1 << p));
                    if (it != s.end() and *it <= r) {
                        l += (1 << p);
                    }
                    else {
                        r -= (1 << p);
                    }
                }
                else {
                    auto it = s.lower_bound(l);
                    if (it != s.end() and *it < l + (1 << p)) {
                        r -= (1 << p);
                    }
                    else {
                        l += (1 << p);
                    }
                }
            }

            cout << (x ^ l) << "\n";
        }
    }
    return 0;
}