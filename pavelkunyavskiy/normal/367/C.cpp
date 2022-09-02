//#include <iostream>
#include <fstream>
#include <numeric>
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

ll get(int n){
    if (n % 2 == 0)
        return n * 1LL * (n - 1) / 2 + n / 2;
    return n * 1LL * (n - 1) / 2 + 1;
}


int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif

    int _n,m;
    scanf("%d %d",&_n, &m);

    int n = 1;
    while (get(n) <= _n)
       n++;
    n--;

    map<int,ll> v;
    for (int i = 0; i < m; i++){
        int x, y;
        scanf("%d %d",&x,&y);
        v[x] += y;
    }

    vector<ll> res;
    for (map<int,ll>::iterator iter = v.begin(); iter != v.end(); ++iter)
        res.pb(iter->second);

    sort(res.begin(), res.end());
    reverse(res.begin(), res.end());
    res.resize(min(n, (int)res.size()));
    printf(LLD"\n", accumulate(res.begin(), res.end(), 0LL));
    return 0;
}