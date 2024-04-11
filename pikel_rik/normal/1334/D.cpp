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

int n; ll l, r;

bool check(ll i) {
    return i >= l and i <= r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        cin >> n >> l >> r;

        vector<int> ans = {1};

        if (l != 1)
            ans.pop_back();

        for (int i = 0; i < n - 2; i++) {
            if (check(1 + 2 * i + 1))
                ans.push_back(i + 2);
            if (check(1 + 2 * i + 2))
                ans.push_back(1);
        }

        if (check(2 + 2 * (n - 2)))
            ans.push_back(n);

        ll extra = 2 + 2 * (n - 2), sum = extra;
        for (int i = 2; i < n; i++) {
            extra += 2 + 2 * (n - i - 1);
            if (extra < l) {
                sum = extra;
                continue;
            }
            if (sum > r)
                break;

            if (check(sum + 1))
                ans.push_back(i); //2 + 2 * (n - i - 1)
            sum++;

            for (int j = i + 1; j < n; j++) {
                if (check(sum + 1))
                    ans.push_back(j);
                sum++;
                if (check(sum + 1))
                    ans.push_back(i);
                sum++;
            }

            if (check(sum + 1))
                ans.push_back(n);
            sum++;
        }

        if (check(sum + 1))
            ans.push_back(1);

        for (int i : ans) cout << i << " "; cout << "\n";
    }
    return 0;
}