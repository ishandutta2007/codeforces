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


char s[1010][1010];
int n;

void addedge(int u, int v){
    assert(u != v);
    assert(s[u][v] != 'Y');
    s[u][v] = s[v][u] = 'Y';
}


int solve(int f, int t, int k){
    for (int i = 2; i * i <= k; i++)
        if (k % i == 0){
            int ne = n++;
            assert(n <= 1000);
            int tmp = solve(f, ne, i);
            tmp += solve(ne, t, k / i);
            return tmp;
        }
    if (k == 1) {
        int ne = n++;
        addedge(f, ne);
        addedge(ne, t);
        return 2;
    }
    int tmp = solve(f, t, k - 1);
    for (int i = 0; i < tmp; i++){
        int nf = (i == tmp - 1 ? t : n++);
        addedge(f, nf);
        f = nf;
    }
    return tmp;
}



int main(){
  #ifdef LOCAL
    assert(freopen(TASKNAME".in","r",stdin));
    assert(freopen(TASKNAME".out","w",stdout));
  #endif

    int k;
    scanf("%d", &k);

    n = 2;
    memset(s, 'N', sizeof(s));

    solve(0, 1, k);

    printf("%d\n", n);
    for (int i = 0; i < n; i++)
        s[i][n] = 0, puts(s[i]);
    return 0;
}