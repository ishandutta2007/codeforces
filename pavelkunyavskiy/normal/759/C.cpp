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

#define TASKNAME "C"

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


const int MAXN = 1 << 18;

const int INF = 1e9;
int upd[MAXN];
int tree[MAXN];

void add(int v, int val) {
    upd[v] += val;
    tree[v] += val;
}

void push(int v) {
    add(2 * v, upd[v]);
    add(2 * v + 1, upd[v]);
    upd[v] = 0;
}

void recalc(int v) {
    tree[v] = max(tree[2 * v], tree[2 * v + 1]);
}

void update(int v, int l, int r, int L, int R, int val) {
    if (r < L || R < l) return;
    if (L <= l && r <= R) {
        add(v, val);
        return;
    }
    push(v);
    update(2 * v, l, (l + r) / 2, L, R, val);
    update(2 * v + 1, (l + r) / 2 + 1, r, L, R, val);
    recalc(v);
}


int main() {
#ifdef LOCAL
    assert(freopen(TASKNAME".in", "r", stdin));
    assert(freopen(TASKNAME".out", "w", stdout));
#endif

    int n;
    scanf("%d", &n);
    vector<int> x(n, -1);

    int lst = 2;
    while (lst < n) lst *= 2;
    update(1, 0, lst - 1, 0, lst - 1, -INF);

    for (int i = 0; i < n; i++) {
        int p, t;
        scanf("%d%d", &p, &t);
        --p;
        if (t == 1) {
            update(1, 0, lst - 1, p, p, +INF);
            scanf("%d", &x[p]);
            if (p) {
                update(1, 0, lst - 1, 0, p - 1, +1);
            }
        } else {
            if (p) {
                update(1, 0, lst - 1, 0, p - 1, -1);
            }
        }

//        for (int j = 1; j < 2 * lst; j++) {
//            push(j);
//            eprintf("%d ", tree[j]);
//        }
//        eprintf("\n");


        if (tree[1] < 0) {
            printf("-1\n");
        } else {
            int v = 1;
            while (v < lst) {
                push(v);
                if (tree[2 * v + 1] >= 0) {
                    v = 2 * v + 1;
                } else {
                    assert(tree[2 * v] >= 0);
                    v = 2 * v;
                }
            }
            assert(x[v - lst] >= 0);
            printf("%d\n", x[v - lst]);
        }

    }

    return 0;
}