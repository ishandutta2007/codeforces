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
const int N = 3e5 + 5;
const int L = 5e5 + 5;

int n;
pair<int, int> c[N];

int dist(int a, int b, int c, int d) {
    if (a <= b and c <= d)
        return max(b - a, d - c);
    if (a >= b and c >= d)
        return max(a - b, c - d);
    return abs(a - b) + abs(c - d);
}

map<pair<int, int>, int> mp2;

int search(int i, int j) {
    if (mp2.count({i, j}))
        return mp2[{i, j}];

    int mx = 0;
    for (int k = 0; k < n; k++) {
        mx = max(mx, dist(c[k].first, i, c[k].second, j));
    }
    mp2[{i, j}] = mx;
    return mx;
}

map<int, pair<int, int>> mp;

pair<int, int> search(int i) {
    if (mp.count(i))
        return mp[i];

    int lo = 0, hi = L;

    while (hi - lo > 2) {
        int mid1 = lo + (hi - lo) / 3, mid2 = hi - (hi - lo) / 3;
        int f1 = search(i, mid1), f2 = search(i, mid2);

        if (f1 == f2)
            lo = mid1, hi = mid2;
        else if (f1 < f2)
            hi = mid2;
        else lo = mid1;
    }

    int best = 0, best_val = INT_MAX;
    for (int j = lo; j <= hi; j++) {
        int temp = search(i, j);
        if (temp <= best_val) {
            best = j;
            best_val = temp;
        }
    }
    mp[i] = make_pair(best_val, best);
    return make_pair(best_val, best);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    int mn_len = L, mx_len = 0;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (char ch : s) {
            if (ch == 'B')
                c[i].first++;
            else c[i].second++;
        }
        mn_len = min(mn_len, c[i].first + c[i].second);
        mx_len = max(mx_len, c[i].first + c[i].second);
    }

    int lo = 0, hi = L;

    while (hi - lo > 2) {
        int mid1 = lo + (hi - lo) / 3, mid2 = hi - (hi - lo) / 3;
        int f1 = search(mid1).first, f2 = search(mid2).first;

        if (f1 == f2)
            lo = mid1, hi = mid2;
        else if (f1 < f2)
            hi = mid2;
        else lo = mid1;
    }

    int best = INT_MAX, x = 0, y = 0;
    for (int i = lo; i <= hi; i++) {
        auto[temp1, temp2] = search(i);
        if (temp1 <= best) {
            best = temp1;
            x = i;
            y = temp2;
        }
    }

    cout << best << "\n";
    while (x--) cout << 'B';
    while (y--) cout << 'N';
    return 0;
}