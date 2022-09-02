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

char s[110][110];

int main(){
#ifdef LOCAL
    assert(freopen(TASKNAME".in","r",stdin));
    assert(freopen(TASKNAME".out","w",stdout));
#endif
    int n;
    while (scanf("%d",&n) == 1){
        for (int i = 0; i < n; i++)
            scanf("%s", s[i]);
        vector<int> deg(n);
        vector<int> need(n);
        for (int i = 0; i < n; i++)
            scanf("%d",&need[i]);
        if (find(need.begin(), need.end(), 0) == need.end()){
            printf("0\n");
            continue;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (s[i][j] == '1') {
                    deg[j]++;
                }
            }
        }
        for (int i = 0; i < n; i++)
            deg[i] -= need[i];
        vector<int> got(n, 1);
        for (;;) {
            int id = find(deg.begin(), deg.end(), 0) - deg.begin();
            if (id == n) break;
            assert(got[id]);
            got[id] = 0;
            for (int i = 0; i < n; i++)
                if (s[id][i] == '1')
                    deg[i]--;
        }
        printf("%d\n", accumulate(got.begin(), got.end(), 0));
        for (int i = 0; i < n; i++)
            if (got[i])
                printf("%d ", i+1);
        printf("\n");
    }
      
  return 0;
}