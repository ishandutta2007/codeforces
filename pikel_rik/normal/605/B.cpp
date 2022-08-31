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
const int N = 1e5 + 5;

int n;
pair<pair<int, int>, int> a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> a[i].first.first >> a[i].first.second;
        a[i].second = i;
    }

    sort(a, a + m, [&] (const pair<pair<int, int>, int>& x, const pair<pair<int, int>, int>& y) {
        if (x.first.first != y.first.first)
            return x.first.first < y.first.first;
        return x.first.second > y.first.second;
    });

    vector<pair<int, int>> extra;

    for (int i = 1; i <= n and extra.size() < m; i++) {
        for (int j = 1; j <= i - 2 and extra.size() < m; j++) {
            extra.emplace_back(i, j);
        }
    }

    vector<int> used = {1};
    vector<pair<int, int>> edges(m);

    int c = 0, ptr = 0;

    for (int i = 0; i < m; i++) {
        int f = a[i].first.second, idx = a[i].second;
        if (f == 1) {
            edges[idx] = {used.back(), used.back() + 1};
            used.push_back(used.back() + 1);
            continue;
        }
        if ((used.size() * (ll)(used.size() - 1)) / 2 - (used.size() - 1) - c == 0) {
            cout << "-1\n";
            return 0;
        }
        edges[idx] = extra[ptr++];
        c++;
    }

    for (int i = 0; i < m; i++) {
        cout << edges[i].first << " " << edges[i].second << "\n";
    }
    return 0;
}