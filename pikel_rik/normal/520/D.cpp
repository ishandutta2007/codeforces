#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 9;
const int inf = INT_MAX;
const int N = 1e5;

int n;
pair<int, int> a[N];
set<int> g[N], grev[N];

bool check(int i) {
    bool ok = true;
    for (int x : grev[i]) {
        ok &= g[x].size() > 1;
    }
    return ok;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    map<pair<int, int>, int> mp;

    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        mp[a[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        pair<int, int> p = {a[i].first - 1, a[i].second - 1};
        if (mp.count(p)) {
            g[i].insert(mp[p]);
            grev[mp[p]].insert(i);
        }
        p = {a[i].first, a[i].second - 1};
        if (mp.count(p)) {
            g[i].insert(mp[p]);
            grev[mp[p]].insert(i);
        }
        p = {a[i].first + 1, a[i].second - 1};
        if (mp.count(p)) {
            g[i].insert(mp[p]);
            grev[mp[p]].insert(i);
        }
    }

    set<int> s;
    for (int i = 0; i < n; i++) {
        if (check(i))
            s.insert(i);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int num;
        if (i & 1)
            num = *s.begin();
        else num = *s.rbegin();

        ans = (ans * (ll)n + num) % mod;
        s.erase(num);

        for (int x : g[num]) {
            grev[x].erase(num);
            if (check(x))
                s.insert(x);
            else s.erase(x);
        }

        for (int x : grev[num]) {
            g[x].erase(num);
            for (int y : g[x]) {
                if (check(y))
                    s.insert(y);
                else s.erase(y);
            }
        }
    }

    cout << ans << "\n";
    return 0;
}