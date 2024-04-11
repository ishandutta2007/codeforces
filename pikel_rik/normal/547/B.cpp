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
const int N = 2e5 + 5;

int n, a[N], bit[N];

void add(int i, int val) {
    while (i < N) {
        bit[i] = max(bit[i], val);
        i += i & -i;
    }
}

int query(int i) {
    int ans = 0;
    while (i > 0) {
        ans = max(ans, bit[i]);
        i -= i & -i;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<pair<int, int>> v(n);

    stack<int> s;
    for (int i = 0; i < n; i++) {
        while (!s.empty() and a[s.top()] >= a[i])
            s.pop();

        if (s.empty())
            v[i].first = -1;
        else v[i].first = s.top();

        s.push(i);
    }

    while (!s.empty())
        s.pop();

    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() and a[s.top()] >= a[i])
            s.pop();

        if (s.empty())
            v[i].second = n;
        else v[i].second = s.top();

        s.push(i);
    }

    vector<int> ans(n + 1);
    for (int i = 0; i < n; i++) {
        int l = v[i].second - v[i].first - 1;
        ans[l] = max(ans[l], a[i]);
    }

    int m = 0;
    for (int i = n; i >= 1; i--) {
        m = max(m, ans[i]);
        ans[i] = m;
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    return 0;
}