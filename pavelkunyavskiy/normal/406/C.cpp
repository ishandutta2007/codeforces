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

const int MAXN = 110000;

int mt[MAXN];

vector<int> g[MAXN];
int used[MAXN];


int cnt;

bool dfs(int v, int p){
    used[v] = 1;
    int last = -1;
    for (int i = 0; i < (int)g[v].size(); i++){
        int to = g[v][i];
        if (to == p) continue;
        if (used[to] == 2) continue;
        if (used[to] == 1 || !dfs(to, v)){
            if (last != -1)
                printf("%d %d %d\n", last + 1, v + 1, to + 1), last = -1, cnt++;
            else
                last = to;
        }       
    }
    used[v] = 2;
    if (last == -1)
        return false;
    assert(p != -1);
    printf("%d %d %d\n", last + 1, v + 1, p + 1);
    cnt++;
    return true;
}

int main(){
  #ifdef LOCAL
    assert(freopen(TASKNAME".in","r",stdin));
    assert(freopen(TASKNAME".out","w",stdout));
  #endif

    int n,m;
    scanf("%d %d",&n,&m);
    if (m % 2 == 1){
        printf("No solution\n");
        return 0;
    }
    for (int i = 0; i < m; i++){
        int a, b;
        scanf("%d%d",&a,&b);
        --a, --b;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(0, -1);
    assert(cnt == m / 2);
      
    return 0;
}