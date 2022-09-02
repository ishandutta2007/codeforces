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

#define TASKNAME "B"

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

const int MAXN = 200010;

int bit[2][MAXN];
int val[MAXN];
int n;

void update(int id, int pos, int val) {
    for (; pos < n; pos = pos | (pos + 1)) {
        bit[id][pos] += val;
    }
}

int get(int id, int r) {
    int ans = 0;
    for (; r != -1; r = (r & (r + 1)) - 1) {
        ans += bit[id][r];
    }
    return ans;
}

int get(int id, int l, int r) {
    return get(id, r) - get(id, l - 1);
}

int main() {
#ifdef LOCAL
    assert(freopen(TASKNAME".in", "r", stdin));
    assert(freopen(TASKNAME".out", "w", stdout));
#endif

    int k, a, b, q;
    scanf("%d%d%d%d%d",&n,&k,&a,&b,&q);

    for (int i = 0; i < q; i++) {
        int ty;
        scanf("%d",&ty);
        if (ty == 1) {
            int p, d;
            scanf("%d%d",&p,&d);
            --p;
            int add0 = max(0, min(d, b - val[p]));
            int add1 = max(0, min(d, a - val[p]));
            val[p] += d;
            update(0, p, add0);
            update(1, p, add1);
        } else if (ty == 2) {
            int p;
            scanf("%d",&p);
            --p;
            printf("%d\n", get(0, 0, p-1) + get(1, p + k, n - 1));
        }
    }


    return 0;
}