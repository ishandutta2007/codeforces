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


double p[110];
double curp[110];
double curv[110];

const double eps = 1e-9;

int main() {
#ifdef LOCAL
    assert(freopen(TASKNAME".in", "r", stdin));
    assert(freopen(TASKNAME".out", "w", stdout));
#endif

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d",&a);
        p[i] = a / 100.0;
        curp[i] = 1;
        curv[i] = 0;
    }

    double ans = 1;

#ifdef LOCAL
    vector<int> v;
#endif

    while (true) {
        int bid = min_element(curv, curv+n) - curv;
#ifdef LOCAL
        v.push_back(bid);
#endif
        eprintf("%d\n", bid);
        curp[bid] *= (1.0 - p[bid]);
        curv[bid] = (1.0 - curp[bid]) / (1.0 - (1.0 - p[bid]) * curp[bid]);
        double add = 1;
        for (int i = 0; i < n; i++)
            add *= (1 - curp[i]);
        ans += 1 - add;
        if (add > 1 - eps) break;
    }

#ifdef LOCAL
    int sum = 0;
    int its = 10000;
    for (int i = 0; i < its; i++) {
        vector<bool> ok(n);
        for (int j = 0; j <= (int)v.size(); j++) {
            assert(j != (int)v.size());
            if (find(ok.begin(), ok.end(), false) == ok.end()) {
                sum += j;
                break;
            }
            double rd = rand() % 100;
            rd /= 100.0;
            if (rd < p[v[j]]) ok[v[j]] = true;
        }
    }
    eprintf("%f %f %f\n", ans, sum * 1.0 / its, (ans - sum * 1.0/its));
#endif
    printf("%.10lf\n", ans);

    return 0;
}