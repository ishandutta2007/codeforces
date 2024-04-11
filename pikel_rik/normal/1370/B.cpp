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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(2*n);
        for (int i = 0; i < 2*n; i++) cin >> a[i];

        vector<int> even, odd;
        for (int i = 0; i < 2*n; i++) {
            if (a[i] & 1)
                odd.push_back(i);
            else even.push_back(i);
        }

        if (odd.size() & 1) {
            odd.pop_back();
            even.pop_back();
        }
        else {
            if (odd.size() >= 2)
                odd.pop_back(), odd.pop_back();
            else even.pop_back(), even.pop_back();
        }

        for (int i = 1; i < odd.size(); i += 2)
            cout << odd[i - 1] + 1 << " " << odd[i] + 1 << "\n";

        for (int i = 1; i < even.size(); i += 2)
            cout << even[i - 1] + 1 << " " << even[i] + 1 << "\n";
    }
    return 0;
}