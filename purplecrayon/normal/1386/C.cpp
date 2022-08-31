#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 4e5+10, MOD = 1e9+7;


struct DSU {
    int n, cnt_bad;
    vector<ar<int, 2>> p;
    vector<bool> bip;
    vector<int> siz;

    int cur_op;
    vector<pair<int, int>> change_cnt;
    vector<pair<int, pair<int, ar<int, 2>>>> change_p;
    vector<pair<int, pair<int, int>>> change_bip, change_sz;

    DSU() {}
    DSU(int _n): n(_n), p(_n), bip(_n, 1), cnt_bad(), cur_op(), siz(n, 1) {
        for (int i = 0; i < n; i++) {
            p[i] = {i, 0};
        }
    }
    bool is_bip() {
        return cnt_bad == 0;
    }
    ar<int, 2> find_set(int v) {
        if (v == p[v][0]) return p[v];
        ar<int, 2> ans = find_set(p[v][0]);
        return {ans[0], ans[1] ^ p[v][1]};
    }
    void union_sets(int u, int v) {
        int me_op = cur_op++;
        auto [a, x] = find_set(u);
        auto [b, y] = find_set(v);
        if (siz[a] < siz[b]) swap(a, b);
        if (a == b) {
            if (x == y) {
                if (bip[a]) {
                    change_cnt.emplace_back(me_op, cnt_bad);
                    cnt_bad++;
                }
                change_bip.emplace_back(me_op, make_pair(a, bip[a]));
                bip[a] = 0;
            }
            return;
        }

        change_p.emplace_back(me_op, make_pair(b, p[b]));
        p[b] = {a, x ^ y ^ 1};

        change_bip.emplace_back(me_op, make_pair(a, bip[a]));
        bip[a] = bip[a] && bip[b];

        change_sz.emplace_back(me_op, make_pair(a, siz[a]));
        siz[a] += siz[b];
    }
    void undo() {
        cur_op--;
        while (sz(change_cnt) && change_cnt.back().first == cur_op) {
            cnt_bad = change_cnt.back().second;
            change_cnt.pop_back();
        }
        while (sz(change_p) && change_p.back().first == cur_op) {
            auto [i, x] = change_p.back().second;
            p[i] = x;

            change_p.pop_back();
        }
        while (sz(change_bip) && change_bip.back().first == cur_op) {
            auto [i, x] = change_bip.back().second;
            bip[i] = x;

            change_bip.pop_back();
        }
        while (sz(change_sz) && change_sz.back().first == cur_op) {
            auto [i, x] = change_sz.back().second;
            siz[i] = x;

            change_sz.pop_back();
        }
    }
};
struct update {
    bool type;
    int a, b;
    update() {
        type = 0;
    }
    update(int _a, int _b): a(_a), b(_b) {
        type = 0;
    }
    update(ar<int, 2> e) {
        a = e[0], b = e[1];
        type = 0;
    }
};
struct noam_stack {
    DSU d;
    void init(int n) {
        d = DSU(n);
    }
    void push(update u) {
        d.union_sets(u.a, u.b);
    }
    void pop() {
        d.undo();
    }
    bool is_bip() {
        return d.is_bip();
    }
};

template<typename D, typename U>
struct noam : public D {
    vector<U> s;
    void push(const U &u) {
        D::push(u);
        s.push_back(u);
    }
    void pop() {
        auto i = s.end();
        int c = 0;
        do {
            c += (--i)->type ? 1 : -1;
            D::pop();
        }while(c < 0 && i != s.begin());
        auto j = stable_partition(i, s.end(), [](auto &x) { return !x.type; });
        if(i == s.begin()) {
            reverse(i, j);
            for_each(i, j, [](auto &x) { x.type = 1; });
        }
        s.pop_back();
        while(i != s.end()) D::push(*i), i++;
    }
};
using noam_queue = noam<noam_stack, update>;

int n, m, q;
ar<int, 2> ed[MAXN];
int smallest_r[MAXN];

void solve() {
    cin >> n >> m >> q;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b, --a, --b;
        ed[i] = ed[i+m] = {a, b};
    }
    noam_queue d; d.init(n);
    for (int i = 0, ptr = 0; i <= m; i++) {
        while (ptr < 2*m && d.is_bip()) {
            d.push(update(ed[ptr]));
            ptr++;
        }
        if (d.is_bip()) smallest_r[i] = -1;
        else smallest_r[i] = ptr;
        d.pop();
    }
    while (q--) {
        int l, r; cin >> l >> r, --l, --r;
        if (smallest_r[r+1] == -1) {
            cout << "NO\n";
            continue;
        }
        cout << (smallest_r[r+1]-m <= l ? "YES\n" : "NO\n");
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}