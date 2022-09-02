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



const int MAXN = 110000;
int p[MAXN];
int can[2][MAXN];

int get(int a) {
    if (a == p[a]) return a;
    return p[a] = get(p[a]);
}


void join(int a, int b) {
    a = get(a);
    b = get(b);
    p[a] = b;
    can[0][b] &= can[0][a];
    can[1][b] &= can[1][a];
}


int main(){
  #ifdef LOCAL
    assert(freopen(TASKNAME".in","r",stdin));
    assert(freopen(TASKNAME".out","w",stdout));
  #endif
    int n, a, b;
    scanf("%d%d%d",&n,&a,&b);
    vector<pair<int,int>> v(n);
    for (int i = 0; i < (int)v.size(); i++) 
        scanf("%d",&v[i].first), v[i].second = i;

    for (int i = 0; i < n; i++)
        p[i] = i, can[0][i] = can[1][i] = 1;

    sort(v.begin(), v.end());

    for (int i = 0; i < (int)v.size(); i++) {
        int x = v[i].first;
        {
        int id = lower_bound(v.begin(), v.end(), mp(a - x, -1)) - v.begin();
        if (id < (int)v.size() && v[id].first == a - x)
            join(v[i].second, v[id].second);
        else
            can[0][get(v[i].second)] = 0;
        }
        {
        int id = lower_bound(v.begin(), v.end(), mp(b - x, -1))  - v.begin();
        if (id < (int)v.size() && v[id].first == b - x)
            join(v[i].second, v[id].second);
        else
            can[1][get(v[i].second)] = 0;
        }
    }

    for (int i = 0; i < n; i++)
        if (!can[0][i] && !can[1][i] && p[i] == i) {
            printf("NO\n");
            return 0;
        }

    printf("YES\n");
    for (int i = 0; i < n; i++)
        printf("%d%c", can[1][get(i)], " \n"[i==n-1]);

      
    return 0;
}