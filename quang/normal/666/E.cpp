#include <bits/stdc++.h>

using namespace std;

const int N = 600010;
const int LOG = 21;
const int MAGIC = sqrt(N);

char s[N];
int n, m;
int id[N];

struct SuffixArray {
    char* s;
    int n;
    int sa[N], tmp[N], pos[N], cnt[N], lcp[N];
    int rmq[LOG][N];
    int log2[N];

    void radix(int len) {
        memset(cnt, 0, sizeof cnt);
        for (int i = 1; i <= n; i++) {
            cnt[sa[i] + len <= n ? pos[sa[i] + len] : 0]++;
        }
        for (int i = 1; i < N; i++) cnt[i] += cnt[i - 1];
        for (int i = n; i; i--) {
            tmp[cnt[sa[i] + len <= n ? pos[sa[i] + len] : 0]--] = sa[i];
        }
        for (int i = 1; i <= n; i++) sa[i] = tmp[i];
    }

    SuffixArray(int n, char* s) : n(n), s(s) {
        for (int i = 1; i <= n; i++) {
            sa[i] = i;
            pos[i] = s[i];
        }
        for (int len = 1; len <= n; len <<= 1) {
            auto cmp = [&](int u, int v) {
                if (pos[u] != pos[v]) return pos[u] < pos[v];
                return (u + len <= n && v + len <= n) ? pos[u + len] < pos[v + len] : u > v;
            };
            radix(len);
            radix(0);
            tmp[1] = 1;
            for (int i = 2; i <= n; i++) tmp[i] = tmp[i - 1] + cmp(sa[i - 1], sa[i]);
            for (int i = 1; i <= n; i++) {
                pos[sa[i]] = tmp[i];
            }
            if (tmp[n] == n) break;
        }
        

        int curLen = 0;
        for (int i = 1; i <= n; i++) {
            if (pos[i] == n) continue;
            int id = sa[pos[i] + 1];
            while (s[i + curLen] == s[id + curLen]) curLen++;
            lcp[pos[i]] = curLen;
            if (curLen) curLen--;
        }

        // for (int i = 1; i <= n; i++) {
        //     cout << i << ' ' << sa[i] << ' ';
        //     for (int j = sa[i]; j <= n; j++) cout << s[j];
        //         cout << ' ' << lcp[i] << endl;
        // }
        for (int i = 1; i < n; i++) rmq[0][i] = lcp[i];
        for (int i = 1; i < LOG; i++) {
            for (int j = 1; j + (1 << i) - 1 < n; j++) {
                rmq[i][j] = min(rmq[i - 1][j], rmq[i - 1][j + (1 << i - 1)]);
            }
        }
        
        for (int i = 2; i < N; i++) log2[i] = log2[i >> 1] + 1;
    }

    int getRMQ(int l, int r) {
        int lg = log2[r - l + 1];
        return min(rmq[lg][l], rmq[lg][r - (1 << lg) + 1]);
    }

    pair<int, int> get(int u, int len) {
        int id = pos[u];
        int low = 0, high = id;
        while (high - low > 1) {
            int mid = low + high >> 1;
            int sz = getRMQ(mid, id - 1);
            if (sz >= len) high = mid;
            else low = mid;
        }
        int l = high;
        low = id - 1, high = n;
        while (high - low > 1) {
            int mid = low + high >> 1;
            int sz = getRMQ(id, mid);
            if (sz >= len) low = mid;
            else high = mid;
        }
        int r = low + 1;
        return make_pair(l, r);
    }
};

struct Query {
    int l, r, u, v, id;

    bool operator < (const Query &o) const {
        if (u / MAGIC != o.u / MAGIC) return u / MAGIC < o.u / MAGIC;
        return v < o.v;
    }
};

Query queries[N];
pair<int, int> res[N];

struct IT {
    pair<int, int> t[N << 2];

    void init(int node, int l, int r) {
        if (l == r) {
            t[node] = {0, -l};
            return;
        }
        int m = l + r >> 1;
        init(node << 1, l, m);
        init(node << 1 | 1, m + 1, r);
        t[node] = max(t[node << 1], t[node << 1 | 1]);
    }

    void update(int node, int l, int r, int id, int delta) {
        if (id > r || id < l) return;
        if (l == r) {
            t[node].first += delta;
            return;
        }
        int m = l + r >> 1;
        update(node << 1, l, m, id, delta);
        update(node << 1 | 1, m + 1, r, id, delta);
        t[node] = max(t[node << 1], t[node << 1 | 1]);
    }

    pair<int, int> get(int node, int l, int r, int x, int y) {
        if (x > r || y < l) return {-1e9, 0};
        if (x <= l && r <= y) return t[node];
        int m = l + r >> 1;
        pair<int, int> p1 = get(node << 1, l, m, x, y);
        pair<int, int> p2 = get(node << 1 | 1, m + 1, r, x, y);
        return max(p1, p2);
    }
} it;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> (s + 1);
    n = strlen(s + 1);
    cin >> m;
    for (int i = 1; i <= m; i++) {
        s[++n] = '#';
        cin >> (s + n + 1);
        int len = strlen(s + n + 1);
        for (int j = 1; j <= len; j++) id[n + j] = i;
        n += len;
    }
    int q;
    SuffixArray sa(n, s);
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int l, r, u, v;
        cin >> l >> r >> u >> v;
        tie(u, v) = sa.get(u, v - u + 1);
        queries[i] = {l, r, u, v, i};
    }
    it.init(1, 1, m);
    sort(queries + 1, queries + q + 1);
    int curU = 1, curV = 0;

    auto update = [&](int u, int delta) {
        int pos = id[sa.sa[u]];
        if (pos) it.update(1, 1, m, pos, delta);
    };
    for (int i = 1; i <= q; i++) {
        while (curV > queries[i].v) update(curV--, -1);
        while (curV < queries[i].v) update(++curV, +1);
        while (curU < queries[i].u) update(curU++, -1);
        while (curU > queries[i].u) update(--curU, +1);
        res[queries[i].id] = it.get(1, 1, m, queries[i].l, queries[i].r);
    }
    for (int i = 1; i <= q; i++) {
        cout << -res[i].second << ' ' << res[i].first << '\n';
    }
    return 0;
}