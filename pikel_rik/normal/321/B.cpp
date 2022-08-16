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
const int N = 1e2 + 5;

int n, m, b[N];
pair<int, int> a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        if (s == "ATK")
            a[i].first = 1;
        else a[i].first = 0;
        cin >> a[i].second;
    }

    for (int i = 0; i < m; i++)
        cin >> b[i];

    multiset<int> s;
    for (int i = 0; i < m; i++)
        s.insert(b[i]);

    ll best = 0;
    bool ok = true;

    sort(a, a + n);
    for (int i = 0; i < n and ok; i++) {
        if (a[i].first == 1) {
            auto it = s.lower_bound(a[i].second);
            if (it != s.end())
                best += *it - a[i].second, s.erase(it);
            else ok = false;
        }
        else {
            auto it = s.upper_bound(a[i].second);
            if (it != s.end())
                s.erase(it);
            else ok = false;
        }
    }

    if (ok) {
        while (!s.empty()) {
            best += *s.begin();
            s.erase(s.begin());
        }
    }

    ll sum = 0;
    sort(b, b + m);

    for (int i = 0, j = m - 1; i < n && j >= 0; i++) {
        if (a[i].first == 0) continue;
        if (b[j] >= a[i].second) {
            sum += b[j] - a[i].second;
            j--;
        }
    }

    cout << max(best, sum) << "\n";


    return 0;
}