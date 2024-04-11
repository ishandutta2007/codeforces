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

const int MAXN = 500000;

int upd[MAXN];
int val[MAXN];

void add(int v, int x) {
    upd[v] |= x;
    val[v] |= x;
}

void push(int v) {
    add(2*v, upd[v]);
    add(2*v+1, upd[v]);
    upd[v] = 0;
}

void change(int v, int l, int r, int L, int R, int x) {
    if (r < L || R < l) return;
    if (L <= l && r <= R) {
        add(v, x);
        return;
    }
    push(v);
    change(2*v, l, (l+r)/2, L, R, x);
    change(2*v+1, (l+r)/2 + 1, r, L, R, x);
    val[v] = val[2*v] & val[2*v+1];
}

int get(int v, int l, int r, int L, int R) {
    if (r < L || R < l) return -1;
    if (L <= l && r <= R) {
        return val[v];
    }
    push(v);
    return (get(2*v, l, (l+r)/2, L, R) & get(2*v+1, (l+r)/2+1, r, L, R));
}

int l[MAXN], r[MAXN], q[MAXN];


int main(){
  #ifdef LOCAL
    assert(freopen(TASKNAME".in","r",stdin));
    assert(freopen(TASKNAME".out","w",stdout));
  #endif
    int n;
    scanf("%d",&n);
    int lst = 2;
    while (lst < n) lst *= 2;

    
    int m;
    scanf("%d",&m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d",&l[i],&r[i],&q[i]), --l[i], --r[i];
        change(1, 0, lst-1, l[i], r[i], q[i]);
    }

    for (int i = 0; i < m; i++)
        if (get(1, 0, lst-1, l[i], r[i]) != q[i]) {
            printf("NO\n");
            return 0;
        }
    printf("YES\n");
    for (int i = 0; i < n; i++)
        printf("%d%c", get(1, 0, lst-1, i, i), " \n"[i==n-1]);
      
    return 0;
}