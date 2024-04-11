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
const int N = 2e5 + 5;

string s, t;
int n, m, dp1[N], dp2[N];
vector<int> pos[26];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> s >> t;
    n = s.length();
    m = t.length();

    if (n < m) {
        cout << "No\n";
        return 0;
    }

    if (s.front() != t.front() or s.back() != t.back()) {
        cout << "No\n";
        return 0;
    }

    dp1[0] = 1;
    for (int i = 1; i < n; i++) {
        dp1[i] = dp1[i - 1];
        if (dp1[i - 1] != m and t[dp1[i - 1]] == s[i])
            dp1[i]++;
    }

    dp2[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        dp2[i] = dp2[i + 1];
        if (dp2[i + 1] != m and s[i] == t[m - dp2[i + 1] - 1])
            dp2[i]++;
    }

    for (int i = 0; i < m; i++) {
        pos[t[i] - 'a'].push_back(i);
    }

//    for (int i = 0; i < n; i++) {
//        cout << i << " " << dp1[i] << " " << dp2[i] << "\n";
//    } cout << "\n";

    for (int i = 0; i < n; i++) {
        if (pos[s[i] - 'a'].empty() or dp1[i] + dp2[i] < m) {
            cout << "No\n";
            return 0;
        }

        int l = m - dp2[i], r = dp1[i] - 1;
        if (l > r) swap(l, r);

        int lo = 0, hi = pos[s[i] - 'a'].size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (pos[s[i] - 'a'][mid] >= l)
                hi = mid;
            else lo = mid + 1;
        }

        if (pos[s[i] - 'a'][lo] < l or pos[s[i] - 'a'][lo] > r) {
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";
    return 0;
}