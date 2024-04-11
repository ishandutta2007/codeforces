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

int n, m, k, w;

char s[1010][12][12];

int getCost(int a, int b){
    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cnt += s[a][i][j] != s[b][i][j];
    return cnt * w;
}

int main(){
  #ifdef LOCAL
    assert(freopen(TASKNAME".in","r",stdin));
    assert(freopen(TASKNAME".out","w",stdout));
  #endif

    while (scanf("%d%d%d%d",&n,&m,&k,&w) == 4){
        k++;
        for (int i = 1; i < k; i++)
            for (int j = 0; j < n; j++)
                scanf("%s", s[i][j]);

        vector<int> dst(k, n*m);
        vector<int> dste(k, 0);
        dst[0] = 0, dste[0] = -1;
        vector<pair<int, int> > ans;
        int tot = 0;

        for (int i = 1; i < k; i++) {
            int best = -1;
            for (int j = 0; j < k; j++)
                if (dste[j] >= 0 && (best == -1 || dst[best] > dst[j]))
                    best = j;
            tot += dst[best];
            ans.pb(mp(best, dste[best]));
            dste[best] = -2;
            for (int j = 0; j < k; j++){
                if (dste[j] < 0) continue;
                int temp = getCost(best, j);
                if (temp < dst[j]) {
                    dst[j] = temp;
                    dste[j] = best;
                }
            }               
        }

        printf("%d\n", tot);
        for (int i = 0; i < (int)ans.size(); i++)
            printf("%d %d\n", ans[i].first, ans[i].second);
    }

      
  return 0;
}