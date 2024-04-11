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
const int N = 1e5 + 5;

int n;
string a, b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        cin >> n >> a >> b;

        vector<int> ans;
        int cur1 = 0, cur2 = n - 1, c = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (c % 2 == 0) {
                if (a[cur1] == b[i])
                    ans.push_back(1);
                ans.push_back(i + 1);
                cur1++;
            }
            else {
                if (a[cur2] != b[i])
                    ans.push_back(1);
                ans.push_back(i + 1);
                cur2--;
            }
            c++;
        }

        cout << ans.size() << " "; for (int i : ans) cout << i << " "; cout << "\n";
    }
    return 0;
}