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
const int N = 600 + 5;

int n, l[N], r[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
        if (l[i] == r[i] and l[i] % 2 == 0) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
        if (l[i] % 2 == 0)
            l[i]++;
        if (r[i] % 2 == 0)
            r[i]--;
    }

    string ans;

    int cur = 1;
    for (int i = n - 1; i >= 0; i--) {
        if (l[i] > cur) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }

        r[i] = min(r[i], cur);
        cur += 2;

        if (l[i] == 1) {
            ans = "()" + ans;
            continue;
        }

        int pos = -1;
        stack<int> st;

        for (int j = 0; j < ans.length(); j++) {
            if (ans[j] == '(')
                st.push(1);
            else st.pop();
            if (st.empty() and l[i] <= j + 2 and r[i] >= j + 2) {
                pos = j;
                break;
            }
        }
        if (pos == -1) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
        ans = "(" + ans.substr(0, pos + 1) + ")" + ans.substr(pos + 1, ans.length());
    }

    cout << ans << "\n";
    return 0;
}