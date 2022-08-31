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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int k;
    cin >> k;

    vector<int> a(k);
    for (int i = 0; i < k; i++) cin >> a[i];

    vector<int> ans1, ans2;
    for (int i : a) {
        if (i == 0) {
            ans1.push_back(i);
            ans2.push_back(i);
            break;
        }
    }

    for (int i : a) {
        if (i > 0 and i < 10) {
            ans1.push_back(i);
            break;
        }
    }

    for (int i : a) {
        if (i >= 10 and i < 100) {
            ans2.push_back(i);
            break;
        }
    }

    for (int i : a) {
        if (i > 0 and i < 100 and i % 10 == 0) {
            ans1.push_back(i);
            break;
        }
    }

    for (int i : a) {
        if (i > 0 and i % 100 == 0) {
            ans1.push_back(i);
            ans2.push_back(i);
            break;
        }
    }

    if (ans1.size() > ans2.size()) {
        cout << ans1.size() << "\n";
        for (int i : ans1) cout << i << " ";
    }
    else {
        cout << ans2.size() << "\n";
        for (int i : ans2) cout << i << " ";
    }
    return 0;
}