#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int N = 2000 + 5;

int n, m;
pair<int, int> a[N], c[N];
multiset<pair<int, int>> s[N];
vector<int> x_vals;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
    for (int i = 0; i < m; i++) cin >> c[i].first >> c[i].second;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[j].first <= c[i].first and a[j].second <= c[i].second) {
                x_vals.push_back(c[i].first + 1 - a[j].first);
                s[j].emplace(c[i].first + 1 - a[j].first, c[i].second + 1 - a[j].second);
            }
        }
    }

    x_vals.push_back(0);
    sort(x_vals.begin(), x_vals.end());
    x_vals.erase(unique(x_vals.begin(), x_vals.end()), x_vals.end());

    struct comp {
        bool operator()(int i, int j) {
            if (s[i].begin()->first != s[j].begin()->first)
                return s[i].begin()->first < s[j].begin()->first;
            return i < j;
        }
    };

    set<int, comp> indices;
    multiset<int> mx;
    for (int i = 0; i < n; i++) {
        if (!s[i].empty()) {
            indices.insert(i);
            for (auto& [x, y] : s[i]) {
                mx.insert(y);
            }
        }
    }

    int ans = INT_MAX;
    for (int x : x_vals) {
        while (!indices.empty()) {
            if (s[*indices.begin()].begin()->first <= x) {
                int j = *indices.begin();
                indices.erase(indices.begin());
                while (!s[j].empty() and s[j].begin()->first <= x) {
                    mx.erase(mx.find(s[j].begin()->second));
                    s[j].erase(s[j].begin());
                }
                if (!s[j].empty()) {
                    indices.insert(j);
                }
            } else {
                break;
            }
        }
        ans = min(ans, x + (!mx.empty() ? *mx.rbegin() : 0));
    }
    cout << ans << '\n';
    return 0;
}