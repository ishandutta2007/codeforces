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

#define TASKNAME "A"

#ifdef LOCAL
static struct __timestamper {
    ~__timestamper(){
        TIMESTAMP(end);
    }
} __TIMESTAMPER;
#endif

typedef long long ll;
typedef long double ld;

const int MAXN = 310000;

set<int> s;

int ans[MAXN];


int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif
    int n,m;
    scanf("%d %d",&n,&m);

    memset(ans, -1, sizeof(ans));

    for (int i = 0; i < n; i++)
        s.insert(i);

    for (int i = 0; i < m; i++){
        int l, r, x;
        scanf("%d %d %d",&l,&r,&x);
        --l, --r, --x;
        while (true){
            set<int>::iterator iter = s.lower_bound(l);
            if (iter == s.end() || *iter > r) break;
            if (*iter != x)
                ans[*iter] = x;
            s.erase(iter);
        }
        s.insert(x);
    }

    for (int i = 0; i < n; i++)
        printf("%d%c", ans[i]+1, " \n"[i==n-1]);

      
  return 0;
}