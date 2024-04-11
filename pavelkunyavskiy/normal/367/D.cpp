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
#endif

typedef long long ll;
typedef long double ld;

int cnt[20];
int id[110000];
int mask;

void add(int x, int diff){
    cnt[x] += diff;
    if (cnt[x] == 0) mask |= (1<<x);
    else mask &= ~(1<<x);
}

bool bad[(1<<20)+10];


int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif

    int n,m,d;
    scanf("%d %d %d",&n,&m,&d);

    for (int i = 0; i < m; i++){
        int cnt;
        scanf("%d",&cnt);
        for (int j = 0; j < cnt; j++){
            int x;
            scanf("%d",&x);
            id[x - 1] = i;
        }
    }

    mask = (1<<m) - 1;

    for (int i = 0; i < d; i++){
       add(id[i], 1);
    }

    bad[mask] = 1;
    
    for (int i = d; i < n; i++){
        add(id[i-d], -1);
        add(id[i  ],  1);
        bad[mask] = 1;
    }

    for (int i = (1<<m) - 1; i >= 0; i--)
        if (bad[i])
            for (int j = 0; j < m; j++)
                bad[i & ~(1<<j)] = 1;

    int best = m;

    for (int i = 0; i < (1<<m); i++)
        if (!bad[i])
            best = min(best, __builtin_popcount(i));

    printf("%d\n", best);      
    return 0;
}