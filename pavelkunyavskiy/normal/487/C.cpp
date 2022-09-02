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


int n;
bool check(int root) {
    int x = 1;
    for (int i = 0; i < n - 1; i++) {
        x = (x * 1LL * root) % n;
        if (i != n-2 && x == 1) return 0;
    }
    assert(x == 1);
    return true;
}

int main(){
  #ifdef LOCAL
    assert(freopen(TASKNAME".in","r",stdin));
    assert(freopen(TASKNAME".out","w",stdout));
  #endif

    while (scanf("%d",&n) == 1) {
        if (n == 4) {
            printf("YES\n1\n3\n2\n4\n");
            continue;
        }
        if (n <= 3) {
          printf("YES\n");
          for (int i = 1; i <= n; i++)
              printf("%d\n", i);
          continue;
        }
        bool notp = false;
        for (int i = 2; i < n; i++)
            if (n % i == 0) {
                notp = true;
                printf("NO\n");
                break;
            }
        if (notp) 
            continue;        

        int root = 1;
        while (!check(root))
            root++;

        printf("YES\n");
        vector<int> deg(n);
        deg[0] = 1;
        for (int i = 1; i < n; i++)
            deg[i] = (deg[i-1] * 1LL * root) % n;

        int cur = 1;
        int lf = 1, rg = n - 3;
        vector<bool> used(n, false);
        vector<bool> used2(n, false);
        used[1] = used2[1] = true;
        printf("1\n");
        for (int i = 1; i < n - 1; i++) {
            if (i % 2 == 1) {
                cur = (cur * 1LL * deg[lf]) % n;
                assert(!used2[deg[lf]]); used2[deg[lf]] = true;
                printf("%d\n", deg[lf]);
                lf += 2;
            } else {
                cur = (cur * 1LL * deg[rg]) % n;
                assert(!used2[deg[rg]]); used2[deg[rg]] = true;
                printf("%d\n", deg[rg]);
                rg -= 2;
            }                   
            assert(!used[cur]);
            used[cur] = true;
        }
        assert(!used[0]);
        printf("%d\n", n);
    }
      
    return 0;
}