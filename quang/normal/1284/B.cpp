#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
vector<pair<int, int>>  ls;

struct BIT {
    int t[N * 10];
    void init() {
        memset(t, 0, sizeof t);
    }
    void add(int x, int v) {
        x++;
        while (x < N * 10) {
            t[x] += v;
            x += x & -x;
        }
    }

    int get(int x) {
        x++;
        int res = 0;
        while (x) {
            res += t[x];
            x -= x & -x;
        }
        return res;
    }
} t;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int sz; cin >> sz;
        vector<int> a(sz);
        for (int &u : a) cin >> u;
        int found = 0;
        for (int i = 0; i + 1 < sz; i++) {
            if (a[i] < a[i + 1]) {
                found = 1;
                break;
            }
        }
        if (found) continue;
        ls.push_back({a.back(), a[0]});
    }
    sort(ls.begin(), ls.end());
    long long res = 0;
    for (auto u : ls) {
        res += t.get(u.first);
        t.add(u.second, 1);
        res += u.first == u.second;
    }
    t.init();
    for (int i = (int)ls.size() - 1; i >= 0; i--) {
        auto u = ls[i];
        res += t.get(u.first);
        t.add(u.second, 1);
    }
    cout << 1ll * n * n - res << endl;
    return 0;
}