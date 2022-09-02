//#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <functional>
#include <bitset>
#define mp make_pair
#define pb push_back

#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("["#x"] Time : %.3lf s.\n", clock()*1.0/CLOCKS_PER_SEC)
#define TIMESTAMPf(x,...) eprintf("[" x "] Time : %.3lf s.\n", __VA_ARGS__, clock()*1.0/CLOCKS_PER_SEC)

#if ( ( _WIN32 || __WIN32__ ) && __cplusplus < 201103L)
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

#define TASKNAME "D"

#ifdef LOCAL
static struct __timestamper {
    string what;
    __timestamper(const char* what) : what(what){};
    __timestamper(const string& what) : what(what){};
    ~__timestamper(){
        TIMESTAMPf("%s", what.data());
    }
} __TIMESTAMPER("end");
#else 
struct __timestamper {};
#endif

typedef long long ll;
typedef long double ld;

const int MOD = 1000000007;

int mult(int a, int b) {
    return (int) ((a * 1LL * b) % MOD);
}


int mypow(int a, int b) {
    if (!b) return 1;
    if (b & 1) return mult(mypow(a, b-1), a);
    int temp = mypow(a, b/2);
    return mult(temp, temp);
}


int inv(int a) {
    return mypow(a, MOD - 2);
}

class Tree {
    vector<int> tree;
    vector<int> update;
    int lst;

    void multiply(int v, int val) {
        tree[v] = mult(tree[v], val);
        update[v] = mult(update[v], val);
    }

    void push(int v) {
        multiply(2 * v, update[v]);
        multiply(2 * v + 1, update[v]);
        update[v] = 1;
    }

    void recalc(int v) {
        tree[v] = (tree[2 * v] + tree[2 * v + 1]) % MOD;
    }

    void _set(int v, int l, int r, int pos, int val) {
        if (pos < l || pos > r) return;
        if (l == r) {
            tree[v] = val;
            return;
        }
        push(v);
        _set(2 * v, l, (l + r) / 2, pos, val);
        _set(2 * v + 1, (l + r) / 2 + 1, r, pos, val);
        recalc(v);
    }

    void _upd(int v, int l, int r, int L, int R, int val) {
        if (R < l || r < L)
            return;
        if (L <= l && r <= R) {
            multiply(v, val);
            return;
        }
        push(v);
        _upd(2 * v, l, (l + r) / 2, L, R, val);
        _upd(2 * v + 1, (l + r) / 2 + 1, r, L, R, val);
        recalc(v);
    }

    int _sum(int v, int l, int r, int L, int R) {
        if (R < l || r < L)
            return 0;
        if (L <= l && r <= R) {
            return tree[v];
        }
        push(v);
        return (_sum(2 * v, l, (l + r) / 2, L, R)+_sum(2 * v + 1, (l + r) / 2 + 1, r, L, R)) % MOD;
    }

public:
    Tree(int n) {
        lst = 2;
        while (lst < n) lst *= 2;
        tree.resize(2 * lst);
        update.resize(2 * lst, 1);
    }

    void set(int pos, int val) {
        _set(1, 0, lst - 1, pos, val);
    }

    void upd(int l, int r, int val) {
        _upd(1, 0, lst - 1, l, r, val);
    }

    int sum(int l, int r) {
        return _sum(1, 0, lst - 1, l, r);
    }

};

vector<vector<int>> g;

vector<int> type;
vector<int> id;
vector<int> v0;
vector<int> parent;

vector<int> tin, tout;
vector<int> order;

void dfs(int v) {
    static int timer = 0;
    tin[v] = timer++;
    for (int u : g[v])
        dfs(u);
    tout[v] = timer - 1;
}


int main() {
#ifdef LOCAL
    assert(freopen(TASKNAME".in", "r", stdin));
    assert(freopen(TASKNAME".out", "w", stdout));
#endif

    v0.resize(1);
    g.resize(1);
    parent.push_back(-1);
    int q;
    scanf("%d %d",&v0[0], &q);
    type.resize(q);
    id.resize(q);
    for (int i = 0; i < q; i++) {
        int ty;
        scanf("%d",&ty);
        if (ty == 1) {
            int p, v;
            scanf("%d%d",&p, &v);
            --p;
            id[i] = (int) g.size();
            g[p].push_back(id[i]);
            type[i] = 1;
            g.push_back(vector<int>());
            v0.push_back(v);
            parent.push_back(p);
        } else {
            type[i] = 2;
            scanf("%d", &id[i]);
            --id[i];
        }
    }
    tin.resize(g.size());
    tout.resize(g.size());
    dfs(0);
/*    order.resize(g.size());
    for (int i = 0; i < (int)g.size(); i++)
        order[i] = i;
    sort(order.begin(), order.end(), [](int a, int b) { return tin[a] < tin[b];});*/

    Tree value(g.size());
    value.set(0, v0[0]);

    vector<int> deg(g.size(), 1);

    for (int i = 0; i < q; i++) {
        if (type[i] == 1) {
            int v = id[i];
            int p = parent[v];
            int oldd = deg[p];
            int newd = ++deg[p];
            value.upd(tin[p], tout[p], mult(newd, inv(oldd)));
            int sum = value.sum(tin[p], tin[p]);
            int pcoef = mult(sum, inv(v0[p]));
            //fprintf(stderr, "pcoef = %d\n", pcoef);
            value.set(tin[v], mult(pcoef, v0[v]));
            //fprintf(stderr, "check = %d %d\n", value.sum(tin[v], tin[v]), mult(pcoef, v0[v]));
        } else {
            int v = id[i];
            int ans = value.sum(tin[v], tout[v]);
            int coef = 1;
            if (v) {
                int p = parent[v];
                int sum = value.sum(tin[p], tin[p]);
                int pcoef = mult(sum, inv(v0[p]));
                //fprintf(stderr, "!pcoef = %d\n", pcoef);
                coef = inv(pcoef);
            }
            //fprintf(stderr, "ans = %d\n", ans);
            ans = mult(ans, coef);
            printf("%d\n", ans);
        }
    }

    return 0;
}