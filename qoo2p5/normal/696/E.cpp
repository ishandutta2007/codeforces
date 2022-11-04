#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int INF = 1e9;
const ll LINF = 1e18;

struct SumTree {
    int n;
    ll* tree;
    
    SumTree() {}
    
    SumTree(int nn) {
        n = 1;
        while (n < nn) {
            n *= 2;
        }
        
        tree = new ll[2 * n];
        fill(tree, tree + 2 * n, 0);
    }
    
    void add(int i, int tl, int tr, int l, int r, int val) {
        if (l >= r || tl >= r || tr <= l) {
            return;
        }
        
        if (l <= tl && tr <= r) {
            tree[i] += val;
            return;
        }
        
        int tm = (tl + tr) / 2;
        add(2 * i + 1, tl, tm, l, r, val);
        add(2 * i + 2, tm, tr, l, r, val);
    }
    
    void add(int l, int r, int val) {
        add(0, 0, n, l, r, val);
    }
    
    ll get(int i, int tl, int tr, int ind) {
        if (tl == tr - 1) {
            return tree[i];
        }
        
        int tm = (tl + tr) / 2;
        if (ind < tm) {
            return tree[i] + get(2 * i + 1, tl, tm, ind);
        } else {
            return tree[i] + get(2 * i + 2, tm, tr, ind);
        }
    }
    
    ll get(int ind) {
        return get(0, 0, n, ind);
    }
};

struct MinTree {
    int n;
    pair<ll, int>* tree;
    ll* to_push;
    
    MinTree() {}
    
    MinTree(int nn) {
        n = 1;
        while (n < nn) {
            n *= 2;
        }
        
        tree = new pair<ll, int>[2 * n];
        to_push = new ll[2 * n];
        fill(tree, tree + 2 * n, make_pair(LINF, -1));
        fill(to_push, to_push + 2 * n, 0);
    }
    
    void recalc(int i) {
        tree[i] = min(
            make_pair(tree[2 * i + 1].first + to_push[2 * i + 1], tree[2 * i + 1].second),
            make_pair(tree[2 * i + 2].first + to_push[2 * i + 2], tree[2 * i + 2].second)
        );
    }
    
    void push(int i, int tl, int tr) {
        if (tl != tr - 1) {
            tree[i].first += to_push[i];
            to_push[2 * i + 1] += to_push[i];
            to_push[2 * i + 2] += to_push[i];
            to_push[i] = 0;
        }
    }
    
    void add(int i, int tl, int tr, int l, int r, int val) {
        push(i, tl, tr);
        
        if (l >= r || tl >= r || tr <= l) {
            return;
        }
        
        if (l <= tl && tr <= r) {
            to_push[i] += val;
            push(i, tl, tr);
            return;
        }
        
        int tm = (tl + tr) / 2;
        add(2 * i + 1, tl, tm, l, r, val);
        add(2 * i + 2, tm, tr, l, r, val);
        recalc(i);
    }
    
    void add(int l, int r, int val) {
        add(0, 0, n, l, r, val);
    }
    
    pair<ll, int> get(int i, int tl, int tr, int l, int r) {
        push(i, tl, tr);
        
        if (l >= r || tl >= r || tr <= l) {
            return {LINF, -1};
        }
        
        if (l <= tl && tr <= r) {
            return make_pair(tree[i].first + to_push[i], tree[i].second);
        }
        
        int tm = (tl + tr) / 2;
        return min(get(2 * i + 1, tl, tm, l, r), get(2 * i + 2, tm, tr, l, r));
    }
    
    pair<ll, int> get(int l, int r) {
        return get(0, 0, n, l, r);
    }
    
    void upd(int i, int tl, int tr, int ind, pair<ll, int> val) {
        push(i, tl, tr);
        
        if (tl == tr - 1) {
            tree[i] = {val.first, val.second};
            return;
        }
        
        int tm = (tl + tr) / 2;
        if (ind < tm) {
            upd(2 * i + 1, tl, tm, ind, val);
        } else {
            upd(2 * i + 2, tm, tr, ind, val);
        }
        
        recalc(i);
    }
    
    void upd(int ind, pair<ll, int> val) {
        upd(0, 0, n, ind, val);
    }
};

const int N = 1e5 + 123;

int n, m, q;
vector<int> g[N];
vector<pair<ll, int>> a[N];
int vert[N];

int tree_t;
int tree_left[N], tree_right[N];
SumTree adds;

int parent[N];
int cnt[N];
int depth[N];
int start[N];
int len[N];
MinTree tree[N];

void precalc(int v, int from = -1) {
    tree_left[v] = tree_t++;
    cnt[v] = 1;
    
    for (int u : g[v]) {
        if (u != from) {
            parent[u] = v;
            depth[u] = depth[v] + 1;
            precalc(u, v);
            cnt[v] += cnt[u];
        }
    }
    
    tree_right[v] = tree_t;
}

void build_hld(int v, int from = -1) {
    len[start[v]]++;
    
    bool found = false;
    
    for (int u : g[v]) {
        if (u != from) {
            if (2 * cnt[u] >= cnt[v]) {
                found = true;
                start[u] = start[v];
            } else {
                start[u] = u;
            }
            
            build_hld(u, v);
        }
    }
    
    if (!found) {
        tree[start[v]] = MinTree(len[start[v]]);
    }
}

void push_girl(int v) {
    int u = start[v];
    
    if (!a[v].empty()) {
        pair<ll, int> el = *a[v].rbegin();
        a[v].pop_back();
        tree[u].upd(depth[v] - depth[u], el);
    } else {
        tree[u].upd(depth[v] - depth[u], make_pair(LINF, -1));
    }
}

int get_min(int u, int v) {
    pair<ll, int> best = {LINF, -1};
    
    while (start[u] != start[v]) {
        if (depth[start[u]] < depth[start[v]]) {
            swap(u, v);
        }
        
        pair<ll, int> cur = tree[start[u]].get(0, depth[u] - depth[start[u]] + 1);
        cur.first += adds.get(tree_left[start[u]]);
        best = min(best, cur);
        u = parent[start[u]];
    }
    
    if (depth[u] < depth[v]) {
        swap(u, v);
    }
    
    pair<ll, int> cur = tree[start[u]].get(depth[v] - depth[start[u]], depth[u] - depth[start[u]] + 1);
    cur.first += adds.get(tree_left[start[u]]);
    best = min(best, cur);
    
    if (best.first >= LINF) {
        return -1;
    }
    
    push_girl(vert[best.second]);
    return best.second;
}

int main() {
    scanf("%d%d%d", &n, &m, &q);
    
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    for (int i = 1; i <= m; i++) {
        int c;
        scanf("%d", &c);
        a[c].push_back({i, i});
        vert[i] = c;
    }
    
    for (int i = 1; i <= n; i++) {
        reverse(a[i].begin(), a[i].end());
    }
    
    precalc(1);
    adds = SumTree(tree_t);
    
    start[1] = 1;
    build_hld(1);
    for (int i = 1; i <= n; i++) {
        push_girl(i);
    }
    
    for (int i = 0; i < q; i++) {
        int t;
        scanf("%d", &t);
        
        if (t == 1) {
            int v, u, k;
            scanf("%d%d%d", &v, &u, &k);
            
            vector<int> ans;
            
            while (k) {
                int id = get_min(u, v);
                if (id == -1) {
                    break;
                }
                ans.push_back(id);
                k--;
            }
            
            printf("%d ", (int) ans.size());
            for (int id : ans) {
                printf("%d ", id);
            }
            printf("\n");
        } else {
            int v, k;
            scanf("%d%d", &v, &k);
            
            int u = start[v];
            tree[u].add(depth[v] - depth[u], len[u], k);
            
            adds.add(tree_left[v] + 1, tree_right[v], k);
        }
    }
    
    return 0;
}