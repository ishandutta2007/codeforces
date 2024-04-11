#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const int LOG = 18;

int n;
int a[N];

pair<int, int> join(pair<int, int> u, pair<int, int> v) {
    if (u == pair<int, int>(-1, -1)) return v;
    if (v == pair<int, int>(-1, -1)) return u;
    pair<int, int> res;
    if (u.first > u.second) swap(u, v);
    if (u.first <= u.second && v.first > v.second) {
        v.second += n;
        if (u.second + 1 >= v.first) {
            res.first = min(u.first, v.first);
        } else {
            res.first = v.first;
        }
        if (v.second + 1 >= u.first + n) {
            res.second = max(v.second, u.second + n);
        } else {
            res.second = v.second;
        }
    } else {
        if (u.first > u.second) u.second += n;
        if (v.first > v.second) v.second += n;
        res.first = min(u.first, v.first);
        res.second = max(u.second, v.second);
    }
    if (res.second - res.first + 1 >= n) return {1, n};
    if (res.second > n) res.second -= n;
    return res;
}

struct IT {
    pair<int, int> t[N << 2];

    IT() { 
        memset(t, -1, sizeof t);
    }

    void add(int node, int l, int r, int id, pair<int, int> val) {
        if (id > r || id < l) return;
        if (l == r) {
            t[node] = val;
            return;
        }
        int m = l + r >> 1;
        add(node << 1, l, m, id, val);
        add(node << 1 | 1, m + 1, r, id, val);
        t[node] = join(t[node << 1], t[node << 1 | 1]);
    }

    pair<int, int> get(int node, int l, int r, int x, int y) {
        if (x > y) {
            pair<int, int> foo = get(node, l, r, x, n);
            pair<int, int> bar = get(node, l, r, 1, y);
            return join(foo, bar);
        }
        if (x > r || y < l) return {-1, -1};
        if (x <= l && r <= y) return t[node];
        int m = l + r >> 1;
        pair<int, int> foo = get(node << 1, l, m, x, y);
        pair<int, int> bar = get(node << 1 | 1, m + 1, r, x, y);
        return join(foo, bar);
    }
} it[LOG];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        pair<int, int> foo(i - a[i], i + a[i]);
        if (foo.second - foo.first + 1 >= n) foo = {1, n};
        else if (foo.first <= 0) foo.first += n;
        else if (foo.second > n) foo.second -= n;
        it[0].add(1, 1, n, i, foo);
    }
    for (int i = 1; i < LOG; i++) {
        for (int j = 1; j <= n; j++) {
            pair<int, int> u = it[i - 1].get(1, 1, n, j, j);
            pair<int, int> now = it[i - 1].get(1, 1, n, u.first, u.second);
            it[i].add(1, 1, n, j, now);
        }
    }
    
    for (int i = 1; i <= n; i++) {
        int res = 0;
        pair<int, int> foo = {i, i};
        for (int j = LOG - 1; j >= 0; j--) {
            pair<int, int> bar = it[j].get(1, 1, n, foo.first, foo.second);
            if (bar.first == 1 && bar.second == n) {
                continue;
            }
            foo = bar;
            res |= (1 << j);
        }
        cout << res + 1 << ' ';
    }
    cout << endl;
    return 0;
}