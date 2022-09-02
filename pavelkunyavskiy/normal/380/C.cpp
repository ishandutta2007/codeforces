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

struct item {
    int ans;
    int open, close;

    item(char c){
        ans = open = close = 0;
        if (c == '(') open = 1;
        else {
            assert(c == ')');
            close = 1;
        }
    }
    item() {
        ans = open = close = 0;
    }
};

item merge(item lf, item rg){
    item res;
    res.ans = lf.ans + rg.ans + min(lf.open, rg.close) * 2;
    res.open = rg.open + (lf.open - min(lf.open, rg.close));
    res.close = lf.close + (rg.close - min(lf.open, rg.close));
/*  eprintf("(%d, %d, %d) + (%d, %d, %d) = (%d, %d, %d)\n", lf.ans, lf.open, lf.close,
                                                          rg.ans, rg.open, rg.close,
                                                          res.ans, res.open, res.close);*/
    return res;
}



item tree[(1<<21) + 10];
char s[1100000];
int lst;

int get(int l, int r){
    l += lst;
    r += lst + 1;
    item resl, resr;
    while (l < r){
//      eprintf("[%d..%d]\n", l, r);
        if (l & 1) resl = merge(resl, tree[l]), l++;
        if (r & 1) r--, resr = merge(tree[r], resr);
        l /= 2;
        r /= 2;
    }
    return merge(resl, resr).ans;
}


int main(){
  #ifdef LOCAL
    assert(freopen(TASKNAME".in","r",stdin));
    assert(freopen(TASKNAME".out","w",stdout));
  #endif
    gets(s);
    int n = strlen(s);
    lst = 2;
    while (lst < n) lst *= 2;
    for (int i = lst; i < lst + n; i++) 
        tree[i] = item(s[i - lst]);
    for (int i = lst - 1; i >= 1; i--)
        tree[i] = merge(tree[2*i], tree[2*i+1]);

//      eprintf("\n");

    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++){
        int l, r;
        scanf("%d %d", &l, &r);
        l--, r--;
        printf("%d\n", get(l, r));
    }
      
    return 0;
}