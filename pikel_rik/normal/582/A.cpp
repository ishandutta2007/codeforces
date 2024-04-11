#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ordered_set = tree<int, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 504 * 504;

int n;
multiset<int, greater<>> s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n * n; i++) {
        int a; cin >> a;
        s.insert(a);
    }

    vector<int> ans;

    while (!s.empty()) {
        int a = *s.begin();
        s.erase(s.find(a));
        for (int i : ans) {
            s.erase(s.find(__gcd(a, i)));
            s.erase(s.find(__gcd(a, i)));
        }
        ans.push_back(a);
    }

    for (int i : ans) cout << i << " ";
    return 0;
}