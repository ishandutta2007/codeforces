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

#define TASKNAME "B"

typedef long long ll;
typedef long double ld;

const int MAXN = 110000;

int a[MAXN];
int next[MAXN];
bool used[MAXN];


int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
        scanf("%d",&a[i]), next[i] = i+1;

    vector<int> curq;
    for (int i = n-2; i >= 0; i--)
        if (a[i] >= a[i+1])
            curq.pb(i);


    int ans = 0;
    while (!curq.empty()){
        vector<int> nq;
        bool any = false;
        for (int i = 0; i < (int)curq.size(); i++){
            int v = curq[i];
            if (used[v]) continue;
            if (next[v] == n) continue;
//          eprintf("%d killed %d\n",a[v], a[next[v]]);
            any = true;
            assert(a[v] >= a[next[v]]);
            used[next[v]] = true;
            next[v] = next[next[v]];
            if (a[v] >= a[next[v]])
                nq.pb(v);
        }
        curq = nq;
        ans += any;
/*      eprintf("!!! %d\n",(int)any);
        for (int i = 0; i < n; i++)
            if (!used[i])
                eprintf("%d ",a[i]);
        eprintf("\n");*/
    }

    printf("%d\n",ans);
    
      
    TIMESTAMP(end);
    return 0;
}