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


int main() {
#ifdef LOCAL
    assert(freopen(TASKNAME".in", "r", stdin));
    assert(freopen(TASKNAME".out", "w", stdout));
#endif

    int lim, d, n;
    scanf("%d%d%d",&d, &lim, &n);
    vector<pair<int, int>> v(n);

    for (auto& x : v) {
        scanf("%d%d", &x.first, &x.second);
    }
    n++;
    v.push_back(make_pair(0, 0));

    sort(v.rbegin(), v.rend());

    int last = d;
    vector<pair<int, int>> st;
    for (int i = 0; i < n; i++) {
        int cur = last - v[i].first;
        if (cur > lim) {
            printf("-1\n");
            return 0;
        }
        while (cur < lim && !st.empty() && st.back().first > v[i].second) {
            int diff = min(lim - cur, st.back().second);
            st.back().second -= diff;
            cur += diff;
            if (st.back().second == 0) st.pop_back();
        }
        st.push_back(make_pair(v[i].second, cur));
        last = v[i].first;
    }

    long long ans = 0;

    for (auto x : st) {
        ans += x.first * 1LL * x.second;
    }

    printf("%lld\n", ans);

    return 0;
}