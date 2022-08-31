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

int mex(const vector<int>& a) {
    int n = a.size();
    set<int> s;
    for (int i = 0; i <= n; i++)
        s.insert(i);

    for (int i : a) s.erase(i);
    return *s.begin();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<int> ans;
        int c = 0;

        while (true) {
            bool flag = true;
            for (int i = 1; i < a.size(); i++) {
                if (a[i] < a[i - 1])
                    flag = false;
            }
            if (flag)
                break;

            int x = mex(a);
            if (x == a.size()) {
                ans.push_back(x - 1);
                a.pop_back();
            }
            else {
                a[x] = x;
                ans.push_back(x);
            }
        }

//        for (int i : a) cout << i << " "; cout << "\n";

        cout << ans.size() << "\n";
        for (int i : ans) cout << i + 1 << " "; cout << "\n";
    }
    return 0;
}