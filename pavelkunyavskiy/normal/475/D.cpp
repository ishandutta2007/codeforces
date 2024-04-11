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
#else 
struct __timestamper {};
#endif

typedef long long ll;
typedef long double ld;



int main(){
  #ifdef LOCAL
    assert(freopen(TASKNAME".in","r",stdin));
    assert(freopen(TASKNAME".out","w",stdout));
  #endif

    vector<pair<int, int>> val;
    val.pb(mp(-1, -1));

    int n;
    scanf("%d",&n);
    vector<int> xs(n);
    for (int& x : xs)
        scanf("%d",&x);
    int m;
    scanf("%d",&m);
    vector<pair<int, int>> reqs(m);
    for (int i = 0; i < m; i++)
        scanf("%d",&reqs[i].first), reqs[i].second = i;
    vector<ll> ans(m);
    sort(reqs.begin(), reqs.end(), [](const pair<int,int>& a, const pair<int,int>& b){ return a.first < b.first;});
    for (int i = 0; i < n; i++) {
        int x = xs[i];
        val.pb(mp(x, i));
        for (int j = 1; j < (int)val.size(); j++)
            val[j].first = __gcd(val[j].first, x);
        int ptr = 0;
        for (int j = 0; j < (int)val.size(); j++) {
            if (j && val[j].first == val[ptr-1].first)
                val[ptr-1] = val[j];
            else
                val[ptr++] = val[j];
        }
        val.resize(ptr);

        for (int j = 1; j < (int)val.size(); j++) {
            int x = val[j].first;
            int y = val[j].second - val[j-1].second;
            int id = lower_bound(reqs.begin(), reqs.end(), mp(x, -1)) - reqs.begin();
            if (reqs[id].first == x) {
               ans[id] += y;
            }
        }
    }

    for (int i = 1; i < m; i++)
        if (reqs[i].first == reqs[i-1].first)
            ans[i] = ans[i-1];

    vector<ll> ans2(m);
    for (int i = 0; i < m; i++)
        ans2[reqs[i].second] = ans[i];

    for (const ll& x : ans2)
        printf("%I64d\n", x);
    return 0;
}