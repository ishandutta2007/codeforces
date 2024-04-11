/* Author: izhang05
 * Time: 07-16-2021 23:45:55
**/
#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen(("in" + name + ".txt").c_str(), "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("out.txt", "w", stderr);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 3e5 + 5, maxs = 20;
vector<int> adj[maxn];

int up[maxn][maxs], depth[maxn], n;

int jmp(int x, int d) {
    for (int i = 0; i < maxs; i++) {
        if ((d >> i) & 1) {
            x = up[x][i];
        }
    }
    return x;
}

int lca(int x, int y) {
    if (depth[x] < depth[y]) {
        swap(x, y);
    }
    x = jmp(x, depth[x] - depth[y]);
    if (x == y) {
        return x;
    }
    for (int i = maxs - 1; i >= 0; --i) {
        int new_x = up[x][i], new_y = up[y][i];
        if (new_x != new_y) {
            x = new_x, y = new_y;
        }
    }
    return up[x][0];
}

void build() {
    for (int i = 1; i < maxs; ++i) {
        for (int j = 0; j < n; ++j) {
            if (up[j][i - 1] == -1) {
                up[j][i] = -1;
            } else {
                up[j][i] = up[up[j][i - 1]][i - 1];
            }
        }
    }
}

int tin[maxn], tout[maxn], euler[2 * maxn], t, color[maxn], add_l[maxn], occ[maxn], color_occ[maxn], sum_block[maxn], val[maxn];
void dfs(int c = 0, int p = -1, int d = 0) {
    up[c][0] = p;
    depth[c] = d;
    euler[t] = c;
    tin[c] = t++;
    for (int i : adj[c]) {
        if (i != p) {
            dfs(i, c, d + 1);
        }
    }
    euler[t] = c;
    tout[c] = t++;
}
const int k = 700;
struct query {
    int l, r, x, y, ind;
    bool operator<(query other) const {
        if (l / k != other.l / k) {
            return l < other.l;
        }
        return (l / k & 1) ? (r < other.r) : (r > other.r);
    }
};

int block(int x) {
    return x / k;
}

void add(int x) {
    int cur_occ = ++occ[euler[x]], cur_color = color[euler[x]];
    if (cur_occ == 1) {
        if (++color_occ[cur_color] % 2 == 1) {
            val[cur_color] = 1;
            ++sum_block[block(cur_color)];
        } else {
            val[cur_color] = 0;
            --sum_block[block(cur_color)];
        }
    } else if (cur_occ == 2) {
        if (--color_occ[cur_color] % 2 == 1) {
            val[cur_color] = 1;
            ++sum_block[block(cur_color)];
        } else {
            val[cur_color] = 0;
            --sum_block[block(cur_color)];
        }
    } else {
        assert(false);
    }
}
void rem(int x) {
    int cur_occ = --occ[euler[x]], cur_color = color[euler[x]];
    if (cur_occ == 1) {
        if (++color_occ[cur_color] % 2 == 1) {
            val[cur_color] = 1;
            ++sum_block[block(cur_color)];
        } else {
            val[cur_color] = 0;
            --sum_block[block(cur_color)];
        }
    } else if (cur_occ == 0) {
        if (--color_occ[cur_color] % 2 == 1) {
            val[cur_color] = 1;
            ++sum_block[block(cur_color)];
        } else {
            val[cur_color] = 0;
            --sum_block[block(cur_color)];
        }
    } else {
        assert(false);
    }
}
int sol[maxn];

void solve(query c) {
    sol[c.ind] = -1;
    for (int b = block(c.x); b * k <= c.y; ++b) {
        if (sum_block[b]) {
            for (int i = max(b * k, c.x); i < (b + 1) * k && i <= c.y; ++i) {
                if (val[i]) {
                    sol[c.ind] = i;
                    return;
                }
            }
        }
    }
}

int main() {
    setIO("1");
    int m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> color[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs();
    build();
    vector<query> queries(m);
    for (int i = 0; i < m; ++i) {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        --a, --b;
        if (tin[a] > tin[b]) {
            swap(a, b);
        }
        int l = lca(a, b);
        if (a == l) {
            queries[i] = {tin[a], tin[b], x, y, i};
            add_l[i] = -1;
        } else {
            queries[i] = {tout[a], tin[b], x, y, i};
            add_l[i] = tin[l];
        }
    }
    sort(queries.begin(), queries.end());
    int l = 0, r = -1;
    for (auto &i : queries) {
        while (r < i.r) {
            ++r;
            add(r);
        }
        while (l > i.l) {
            --l;
            add(l);
        }
        while (r > i.r) {
            rem(r);
            --r;
        }
        while (l < i.l) {
            rem(l);
            ++l;
        }
        // if (n == 3e5) {
            // continue;
        // }
        if (add_l[i.ind] != -1) {
            add(add_l[i.ind]);
        }
        solve(i);
        if (add_l[i.ind] != -1) {
            rem(add_l[i.ind]);
        }
    }
    for (int i = 0; i < m; ++i) {
        cout << sol[i] << "\n";
    }
}

///* Author: izhang05
// * Time: 07-16-2021 23:45:55
//**/
//#include <bits/stdc++.h>
//
//using namespace std;
//
////#define DEBUG
//void setIO(const string &name) {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cin.exceptions(istream::failbit);
//#ifdef LOCAL
//    freopen(("in" + name + ".txt").c_str(), "r", stdin);
//    freopen("out.txt", "w", stdout);
//    freopen("out.txt", "w", stderr);
//#endif
//}
//const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxs = 20;
//constexpr int logn = 19;
//constexpr int maxn = 1 << logn;
//
//vector<int> adj[maxn];
//
//int up[maxn][maxs], depth[maxn], n;
//
//int jmp(int x, int d) {
//    for (int i = 0; i < maxs; i++) {
//        if ((d >> i) & 1) {
//            x = up[x][i];
//        }
//    }
//    return x;
//}
//
//int lca(int x, int y) {
//    if (depth[x] < depth[y]) {
//        swap(x, y);
//    }
//    x = jmp(x, depth[x] - depth[y]);
//    if (x == y) {
//        return x;
//    }
//    for (int i = maxs - 1; i >= 0; --i) {
//        int new_x = up[x][i], new_y = up[y][i];
//        if (new_x != new_y) {
//            x = new_x, y = new_y;
//        }
//    }
//    return up[x][0];
//}
//
//void build() {
//    for (int i = 1; i < maxs; ++i) {
//        for (int j = 0; j < n; ++j) {
//            if (up[j][i - 1] == -1) {
//                up[j][i] = -1;
//            } else {
//                up[j][i] = up[up[j][i - 1]][i - 1];
//            }
//        }
//    }
//}
//
//int tin[maxn], tout[maxn], euler[2 * maxn], t, color[maxn], add_l[maxn], occ[maxn], color_occ[maxn], sum_block[maxn], val[maxn];
//void dfs(int c = 0, int p = -1, int d = 0) {
//    up[c][0] = p;
//    depth[c] = d;
//    euler[t] = c;
//    tin[c] = t++;
//    for (int i : adj[c]) {
//        if (i != p) {
//            dfs(i, c, d + 1);
//        }
//    }
//    euler[t] = c;
//    tout[c] = t++;
//}
//
//inline long long gilbertOrder(int x, int y) {
//    long long d = 0;
//    for (int s = 1 << (logn - 1); s; s >>= 1) {
//        bool rx = x & s, ry = y & s;
//        d = d << 2 | rx * 3 ^ static_cast<int>(ry);
//        if (!ry) {
//            if (rx) {
//                x = maxn - x;
//                y = maxn - y;
//            }
//            swap(x, y);
//        }
//    }
//    return d;
//}
//
//
//const int k = 600;
//
//struct query {
//    int l, r, x, y, ind;
//    int64_t ord;
//    inline void calcOrder() {
//        ord = gilbertOrder(l, r);
//    }
//    //    bool operator<(query other) const {
//    //        if (l / k != other.l / k) {
//    //            return l < other.l;
//    //        }
//    //        return (l / k & 1) ? (r < other.r) : (r > other.r);
//    //    }
//};
//inline bool operator<(const query &a, const query &b) {
//	return a.ord < b.ord;
//}
//
//int block(int x) {
//    return x / k;
//}
//
//void add(int x) {
//    int cur_occ = ++occ[euler[x]], cur_color = color[euler[x]];
//    if (cur_occ == 1) {
//        if (++color_occ[cur_color] % 2 == 1) {
//            val[cur_color] = 1;
//            ++sum_block[block(cur_color)];
//        } else {
//            val[cur_color] = 0;
//            --sum_block[block(cur_color)];
//        }
//    } else if (cur_occ == 2) {
//        if (--color_occ[cur_color] % 2 == 1) {
//            val[cur_color] = 1;
//            ++sum_block[block(cur_color)];
//        } else {
//            val[cur_color] = 0;
//            --sum_block[block(cur_color)];
//        }
//    } else {
//        assert(false);
//    }
//}
//void rem(int x) {
//    int cur_occ = --occ[euler[x]], cur_color = color[euler[x]];
//    if (cur_occ == 1) {
//        if (++color_occ[cur_color] % 2 == 1) {
//            val[cur_color] = 1;
//            ++sum_block[block(cur_color)];
//        } else {
//            val[cur_color] = 0;
//            --sum_block[block(cur_color)];
//        }
//    } else if (cur_occ == 0) {
//        if (--color_occ[cur_color] % 2 == 1) {
//            val[cur_color] = 1;
//            ++sum_block[block(cur_color)];
//        } else {
//            val[cur_color] = 0;
//            --sum_block[block(cur_color)];
//        }
//    } else {
//        assert(false);
//    }
//}
//int sol[maxn];
//
//void solve(query c) {
//    sol[c.ind] = -1;
//    for (int b = block(c.x); b * k <= c.y; ++b) {
//        if (sum_block[b]) {
//            for (int i = max(b * k, c.x); i < (b + 1) * k && i <= c.y; ++i) {
//                if (val[i]) {
//                    sol[c.ind] = i;
//                    return;
//                }
//            }
//        }
//    }
//}
//
//int main() {
//    setIO("1");
//    int m;
//    cin >> n >> m;
//    for (int i = 0; i < n; ++i) {
//        cin >> color[i];
//    }
//    for (int i = 0; i < n - 1; ++i) {
//        int a, b;
//        cin >> a >> b;
//        --a, --b;
//        adj[a].push_back(b);
//        adj[b].push_back(a);
//    }
//    dfs();
//    build();
//    vector<query> queries(m);
//    for (int i = 0; i < m; ++i) {
//        int a, b, x, y;
//        cin >> a >> b >> x >> y;
//        --a, --b;
//        if (tin[a] > tin[b]) {
//            swap(a, b);
//        }
//        int l = lca(a, b);
//        if (a == l) {
//            queries[i] = {tin[a], tin[b], x, y, i};
//            add_l[i] = -1;
//        } else {
//            queries[i] = {tout[a], tin[b], x, y, i};
//            add_l[i] = tin[l];
//        }
//        queries[i].calcOrder();
//    }
//    sort(queries.begin(), queries.end());
//    int l = 0, r = -1;
//    for (auto &i : queries) {
//        while (r < i.r) {
//            ++r;
//            add(r);
//        }
//        while (l > i.l) {
//            --l;
//            add(l);
//        }
//        while (r > i.r) {
//            rem(r);
//            --r;
//        }
//        while (l < i.l) {
//            rem(l);
//            ++l;
//        }
//        if (add_l[i.ind] != -1) {
//            add(add_l[i.ind]);
//        }
//        solve(i);
//        if (add_l[i.ind] != -1) {
//            rem(add_l[i.ind]);
//        }
//    }
//    for (int i = 0; i < m; ++i) {
//        cout << sol[i] << "\n";
//    }
//}