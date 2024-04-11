#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

struct Data {
    int l, r;
    int id;

    bool operator<(const Data &o) const {
        if (l != o.l) return l < o.l;
        if (r != o.r) return r < o.r;
        return id < o.id;
    }
};

int n;
Data a[N];
int res[N];

struct ST {
    set<Data> t[N << 2];

    bool canPut(const set<Data> &s, const Data &u) {
        auto it = s.lower_bound(u);
        if (it != s.end()) {
            if (u.l >= it->l && u.r <= it->r) return 0;
        }
        if (it != s.begin()) {
            it--;
            if (u.l >= it->l && u.r <= it->r) return 0;
        }
        return 1;
    }

    void add(int node, int l, int r, int x, const Data &u) {
        if (x > r || x < l) return;
        if (canPut(t[node], u)) {
            while (1) {
                auto it = t[node].lower_bound(u);
                if (it == t[node].end()) break;
                if (u.l <= it->l && u.r >= it->r) {
                    t[node].erase(it);
                } else break;
            }
            while (1) {
                auto it = t[node].lower_bound(u);
                if (it == t[node].begin()) break;
                it--;
                if (u.l <= it->l && u.r >= it->r) {
                    t[node].erase(it);
                } else break;
            }
            t[node].insert(u);
        }
        if (l < r) {
            int m = l + r >> 1;
            add(node << 1, l, m, x, u);
            add(node << 1 | 1, m + 1, r, x, u);
        }
    }

    int get(int node, int l, int r, int x, int y, int val) {
        if (x > r || y < l) return -1;
        if (x <= l && r <= y) { 
            auto it = t[node].lower_bound({val, 0, 0});
            if (it != t[node].end()) {
                if (it->l <= val && val <= it->r) return it->id;
            }
            if (it != t[node].begin()) {
                it--;
                if (it->l <= val && val <= it->r) return it->id;
            }
            return -1;
        }   
        int m = l + r >> 1;
        int p1 = get(node << 1, l, m, x, y, val);
        if (p1 != -1) return p1;
        int p2 = get(node << 1 | 1, m + 1, r, x, y, val);
        return p2;
    }
} t;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].l >> a[i].r;
        a[i].id = i;
    }
    sort(a + 1, a + n + 1);
    set<pair<int, int>> s;
    int cur = 1;
    for (int i = 1; i <= n; i++) {
        while (cur <= n && a[cur].l == i) {
            s.insert({a[cur].r, a[cur].id});
            cur++;
        }
        assert(s.size() > 0);
        pair<int, int> now = *s.begin();
        s.erase(s.begin());
        res[now.second] = i;
    }  
    for (int i = 1; i <= n; i++) {
        int now = t.get(1, 1, n, a[i].l, a[i].r, res[a[i].id]);
        if (now != -1) {
            cout << "NO\n";
            for (int i = 1; i <= n; i++) {
                cout << res[i] << ' ';
            }
            cout << '\n';
            swap(res[a[i].id], res[now]);
            for (int i = 1; i <= n; i++) {
                cout << res[i] << ' ';
            }
            cout << '\n';
            return 0;
        }
        t.add(1, 1, n, res[a[i].id], a[i]);
    }
    cout << "YES\n";
    for (int i = 1; i <= n; i++) {
        cout << res[i] << ' ';
    }
    cout << '\n';
    return 0;
}