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

#define sz(x) ((int)(x).size())

const int inf = (int) 1e9;

typedef long double ld;
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;

class MinCostCirculation {
    struct Edge {
        int to, ne, w, c;
    };
    vector<Edge> es;
    vi firs;
    int curRes;

public:
    MinCostCirculation(int n) : es(), firs(n, -1), curRes(0) {}
    // from, to, capacity (max.flow), cost
    int adde(int a, int b, int w, int c) {
        Edge e;
        e.to = b; e.ne = firs[a];
        e.w = w; e.c = c;
        es.pb(e);
        firs[a] = sz(es) - 1;

        e.to = a; e.ne = firs[b];
        e.w = 0; e.c = -c;
        es.pb(e);
        firs[b] = sz(es) - 1;
        return sz(es) - 2;
    }
    // increase capacity of edge 'id' by 'w'
    void ince(int id, int w) {
        es[id].w += w;
    }
    int solve() {
        const int n = sz(firs);

        for (;;) {
            vi d(n, 0), fre(n, -1);
            vi chd(n, -1);

            int base = -1;
            for (int step = 0; step < n; step++) { /*BOXNEXT*/
                for (int i = 0; i < sz(es); i++) if (es[i].w > 0) {
                        int b = es[i].to;
                        int a = es[i ^ 1].to; /*BOXNEXT*/
                        if (d[b] <= d[a] + es[i].c) continue;
                        d[b] = d[a] + es[i].c;
                        fre[b] = i;
                        if (step == n - 1)
                            base = b;
                    }
            }
            if (base < 0) break;

            vi seq;
            vb was(n, false);/*BOXNEXT*/
            for (int x = base;; x = es[fre[x] ^ 1].to) {
                if (!was[x]) {
                    seq.pb(x);
                    was[x] = true;
                } else {
                    seq.erase(
                            seq.begin(),
                            find(seq.begin(), seq.end(),
                                 x
                            ));
                    break;
                }
            }
            int minv = inf;
            for (int i = 0; i < sz(seq); i++) {
                int v = seq[i];
                int eid = fre[v];
                minv = min(minv, es[eid].w);
            }
            for (int i = 0; i < sz(seq); i++) {
                int v = seq[i];
                int eid = fre[v];
                assert(es[eid].w > 0);
                es[eid].w -= minv;
                es[eid ^ 1].w += minv;
                curRes += es[eid].c * minv;
            }
        }
        return curRes;
    }
};


int main() {
#ifdef LOCAL
    assert(freopen(TASKNAME".in", "r", stdin));
    assert(freopen(TASKNAME".out", "w", stdout));
#endif

    int n;
    scanf("%d",&n);
    MinCostCirculation solver(n);
    solver.adde(n - 1, 0, inf, 0);

    int m;
    scanf("%d",&m);
    int cost = 0;
    for (int i = 0; i < m; i++) {
        int u, v, c, f;
        scanf("%d%d%d%d",&u, &v, &c, &f);
        --u, --v;
        cost += f;
        if (c < f) {
            solver.adde(u, v, c, -1);
            if (f != c) {
                solver.adde(u, v, f - c, 0);
            }
            solver.adde(u, v, inf, 2);
        } else {
            solver.adde(u, v, f, -1);
            if (f != c) {
                solver.adde(u, v, c - f, 1);
            }
            solver.adde(u, v, inf, 2);
        }
    }

    cost += solver.solve();

    printf("%d\n", cost);
    return 0;
}