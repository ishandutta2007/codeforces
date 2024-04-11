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


const int MAXN = 100000;
const int MAXSZ = 1<<18;

ll trees[MAXSZ+10];
int treem[MAXSZ+10];
int lst;

void update(int x){
    trees[x] = trees[2*x] + trees[2*x+1];
    treem[x] = max(treem[2*x], treem[2*x+1]);
}

void setv(int k, int x){
    k += lst;
    trees[k] = treem[k] = x;
    while (k /= 2) {
        update(k);
    }
}

ll get(int v, int l, int r, int L, int R) {
    if (r < L || R < l) return 0;
    if (L <= l && r <= R) return trees[v];
    return get(2*v, l, (l + r) /2, L, R) + get(2*v+1, (l+r)/2+1, r, L, R);
}

void update(int v, int l, int r, int L, int R, int x) {
    if (r < L || R < l) return;
    if (treem[v] < x) return;
    if (v >= lst) {
        trees[v] %= x;
        treem[v] = trees[v];
        return;
    }
    update(2*v, l, (l + r) /2, L, R, x);
    update(2*v+1, (l+r)/2+1, r, L, R, x);
    update(v);
}

int main(){
  #ifdef LOCAL
    assert(freopen(TASKNAME".in","r",stdin));
    assert(freopen(TASKNAME".out","w",stdout));
  #endif

  int n, m;
  scanf("%d%d",&n,&m);
  lst = 2;
  for (;lst < n; lst *= 2);
  for (int i = 0; i < n; i++){
    int x;
    scanf("%d",&x);
    setv(i, x);
  }

  for (int i = 0; i < m; i++){
    int ty;
    scanf("%d",&ty);
    if (ty == 1){
        int l, r;
        scanf("%d %d",&l,&r);
        printf(LLD"\n", get(1, 0, lst-1, l-1, r-1));
    } else if (ty == 2){
        int l, r, x;
        scanf("%d %d %d",&l,&r,&x);
        update(1, 0, lst-1, l-1, r-1, x);
    } else {
        assert(ty == 3);
        int k, x;
        scanf("%d %d",&k,&x);
        setv(k - 1, x);
    }

/*      {
    for (int i = lst; i < lst + n; i++)
        eprintf("%I64d ", trees[i]);
    eprintf("\n");
    }*/
  }


      
  return 0;
}