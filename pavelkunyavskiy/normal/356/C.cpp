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

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

#define TASKNAME "C"

#ifdef LOCAL
static struct __timestamper {
    ~__timestamper(){
        TIMESTAMP(end);
    }
} __TIMESTAMPER;
#endif

typedef long long ll;
typedef long double ld;

int n;
int cnt[5];

void solve(){
    memset(cnt, 0, sizeof(cnt));
    int sum = 0;

    for (int i = 0; i < n; i++){
        int x;
        scanf("%d",&x);
        cnt[x]++;
        sum += x;
    }
    if (sum == 1 || sum == 2 || sum == 5){
        printf("-1\n");
        return;
    }
    int ans = 0;

    {
      int m = min(cnt[1], cnt[2]);
      cnt[0] += m;
      cnt[1] -= m;
      cnt[2] -= m;
      cnt[3] += m;
      ans += m;
    } 
    {
      int m = (cnt[1]/3);
      ans += 2*m;
      cnt[1] -= 3*m;
      cnt[3] += m;
    }
    {
      int m = (cnt[2]/3);
      ans += 2*m;
      cnt[2] -= 3*m;
      cnt[3] += 2*m;
    }
    if (cnt[1] == 1){
        if (cnt[3]) {
            printf("%d\n", ans + 1);
            return;
        } else {
            assert(cnt[4] >= 2);
            printf("%d\n", ans + 2);
            return;
        }
    } 
    if (cnt[1] == 2){
        assert(cnt[4] || cnt[3] >= 2);
        printf("%d\n", ans + 2);
        return;
    }
    assert(cnt[1] == 0);
    if (cnt[2] == 1){
        if (cnt[4]){
            printf("%d\n", ans+1);
            return;
        }
        assert(cnt[3] >= 2);
        printf("%d\n", ans+2);
        return;
    }
    if (cnt[2] == 2){
        printf("%d\n", ans+2);
        return;
    }
    assert(cnt[1] == 0 && cnt[2] == 0);
    printf("%d\n", ans);
}


int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif

   int tests = 0;

   while(scanf("%d",&n) == 1){
      solve();
      ++tests;
      #ifndef LOCAL
        break;
      #endif
   }

   eprintf("%d\n", tests);

      
  return 0;
}