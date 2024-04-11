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


string read() {
    static char buf[100];
    scanf("%s", buf);
    return buf;
}

int main(){
  #ifdef LOCAL
    assert(freopen(TASKNAME".in","r",stdin));
    assert(freopen(TASKNAME".out","w",stdout));
  #endif

    int n;
    while (scanf("%d",&n) == 1) {
        vector<pair<string, string>> f(n);
        for (int i = 0; i < n; i++) {
            f[i].first = read(), f[i].second = read();
            if (f[i].first > f[i].second)
                swap(f[i].first, f[i].second);
        }
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            scanf("%d",&a[i]), --a[i];

        bool fail = false;
        string cur = "";
        for (int i = 0; i < n; i++) {
            if (f[a[i]].first > cur)
                cur = f[a[i]].first;
            else if (f[a[i]].second > cur)
                cur = f[a[i]].second;
            else {
                fail = true;
                break;
            }
        }
        if (fail)
            puts("NO");
        else
            puts("YES");        
    }

      
  return 0;
}