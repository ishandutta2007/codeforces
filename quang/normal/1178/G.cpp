#include <bits/stdc++.h>

using namespace std;

const int N = 200010;
const int MAGIC = sqrt(N / 20) + 10;
const long long INF = 1e18;

int n, q;
vector<int> adj[N];
int a[N], b[N];
int in[N], out[N], cntEuler;
int eulerLs[N];
pair<long long, long long> val[N];

struct Line {
    long long a, b;
    double x;
};

struct Hull {
    vector<Line> h;
    int bot;
    
    Hull() {
        bot = 0;
    }

    void add(long long A, long long B) {
        double X = -INF;
        while (!h.empty()) {
            if (h.back().a == A) {
                if (h.back().b >= B) return;
                h.pop_back();
                continue;
            }
            X = 1.0 * (B - h.back().b) / (h.back().a - A);
            if (X <= h.back().x) h.pop_back();
            else break;
        }
        h.push_back({A, B, X});
    }

    void build(const vector<pair<long long, long long>> &u) {
        bot = 0;
        h.clear();
        for (auto val : u) {
            add(val.first, val.second);
        }
    }

    long long get(long long u) {
        while (bot + 1 < h.size() && h[bot + 1].x <= u) bot++;
        return h[bot].a * u + h[bot].b;
    }
};

struct Block {
    Hull minHull, maxHull;
    vector<int> ls;
    vector<int> id;
    long long off = 0;
    int l, r;
    int firstTime;

    Block() {
        l = N;
        r = -N;
        firstTime = 1;
    }

    void add(int u) {
        ls.push_back(u);
    }

    void build() {
        if (firstTime) {
            id.resize(ls.size());
            for (int i = 0; i < ls.size(); i++) {
                id[i] = i;
            }
            sort(id.begin(), id.end(), [&](int u, int v) {
                return val[ls[u]].second < val[ls[v]].second;
            });
            firstTime = 0;
        }
        vector<pair<long long, long long>> now;
        now.clear();
        now.reserve(ls.size());
        for (int idNow : id) {
            int u = ls[idNow];
            now.push_back({val[u].second, val[u].first * val[u].second});
        }
        maxHull.build(now);

        now.clear();
        now.reserve(ls.size());
        for (int idNow : id) {
            int u = ls[idNow];
            now.push_back({-val[u].second, -val[u].first * val[u].second});
        }
        reverse(now.begin(), now.end());
        minHull.build(now);
    }

    long long get() {
        long long res = -INF;
        res = max(res, abs(minHull.get(off)));
        res = max(res, abs(maxHull.get(off)));
        return res;
    }

    void reset() {
        for (int u : ls) {
            val[u].first += off;
        }
        off = 0;
    }
} block[N / MAGIC + 10];

void dfsInit(int u, long long sumA, long long sumB) {
    in[u] = ++cntEuler;
    eulerLs[cntEuler] = u;
    sumA += a[u];
    sumB += b[u];
    val[u] = {sumA, abs(sumB)};
    for (int v : adj[u]) {
        dfsInit(v, sumA, sumB);
    }
    out[u] = cntEuler;
}

int getPos(int u) {
    return (u + MAGIC - 1) / MAGIC;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 2; i <= n; i++) {
        int u;
        cin >> u;
        adj[u].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    dfsInit(1, 0, 0);
    int maxId = 0;
    for (int i = 1; i <= n; i++) {
        int id = getPos(in[i]);
        block[id].add(i);
        block[id].l = min(block[id].l, in[i]);
        block[id].r = max(block[id].r, in[i]);
        maxId = max(maxId, id);
    }
    for (int i = 1; i <= maxId; i++) {
        block[i].build();
    }
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int v, x;
            cin >> v >> x;
            int l = in[v];
            int r = out[v];
            int lId = getPos(l);
            int rId = getPos(r);
            if (lId == rId) {
                block[lId].reset();
                for (int i = l; i <= r; i++) {
                    val[eulerLs[i]].first += x;
                }
                block[lId].build();
            } else {
                block[lId].reset();
                for (int i = l; i <= block[lId].r; i++) {
                    val[eulerLs[i]].first += x;
                }
                block[lId].build();

                block[rId].reset();
                for (int i = block[rId].l; i <= r; i++) {
                    val[eulerLs[i]].first += x;
                }
                block[rId].build();
                
                for (int i = lId + 1; i < rId; i++) {
                    block[i].off += x;
                }
            }
        } else {
            int v;
            cin >> v;
            int l = in[v];
            int r = out[v];
            int lId = getPos(l);
            int rId = getPos(r);
            long long res = -INF;
            if (lId == rId) {
                block[lId].reset();
                block[lId].build();
                for (int i = l; i <= r; i++) {
                    res = max(res, abs(val[eulerLs[i]].first * val[eulerLs[i]].second));
                }
            } else {
                block[lId].reset();
                for (int i = l; i <= block[lId].r; i++) {
                    res = max(res, abs(val[eulerLs[i]].first * val[eulerLs[i]].second));
                }
                block[lId].build();

                block[rId].reset();
                for (int i = block[rId].l; i <= r; i++) {
                    res = max(res, abs(val[eulerLs[i]].first * val[eulerLs[i]].second));
                }
                block[rId].build();

                for (int i = lId + 1; i < rId; i++) {
                    res = max(res, block[i].get());
                }
            }
            cout << res << '\n';
        }
    }
    return 0;
}