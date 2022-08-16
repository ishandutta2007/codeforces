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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        string s = "abcdefghijklmnopqrstuvwxyz";
        s = s + s;

        vector<string> ans = {s};
        for (int i = 0; i < n; i++) {
            ans.push_back(ans.back());
            if (ans[i][a[i]] != 'a')
                ans[i + 1][a[i]] = 'a';
            else ans[i + 1][a[i]] = 'b';
        }

        for (const string& str : ans) cout << str << "\n";
    }
    return 0;
}