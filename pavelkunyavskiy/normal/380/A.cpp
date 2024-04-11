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

#define TASKNAME "A"

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

int ty[MAXN];
int l[MAXN];
int c[MAXN];
int x[MAXN];




int main(){
  #ifdef LOCAL
    assert(freopen(TASKNAME".in","r",stdin));
    assert(freopen(TASKNAME".out","w",stdout));
  #endif

    int m;
    while (scanf("%d",&m) == 1){
        vector<int> curv;
        vector<ll> len;
        len.pb(0);
        for (int i = 0; i < m; i++){
            scanf("%d",&ty[i]);
            if (ty[i] == 1){
                scanf("%d", &x[i]);
                if ((int)curv.size() < MAXN) curv.pb(x[i]);
                len.pb(len.back() + 1);
            }
            else {
                scanf("%d %d", &l[i], &c[i]);   
                for (int j = 0; j < c[i] && (int)curv.size() < MAXN; j++)
                    for (int k = 0; k < l[i] && (int)curv.size() < MAXN; k++)
                        curv.pb(curv[k]); 
                len.pb(len.back() + l[i] * 1LL * c[i]);
            }
        }
        int n;
        scanf("%d", &n);

        for (int i = 0; i < n; i++){
             ll id;
             scanf(LLD, &id);
             int op = lower_bound(len.begin(), len.end(), id) - len.begin();
             op--;
             if (ty[op] == 1)
                printf("%d ", x[op]);
             else 
                printf("%d ", curv[(id - len[op] - 1) % l[op]]);
        }
        printf("\n");
    }

      
  return 0;
}