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


int main() {
#ifdef LOCAL
    assert(freopen(TASKNAME".in", "r", stdin));
    assert(freopen(TASKNAME".out", "w", stdout));
#endif

    int n;
    scanf("%d", &n);
    vector<int> v(n);
    for (int& x : v) scanf("%d", &x);
    sort(v.begin(), v.end());


    int max = v.back();
    vector<double> prob(max);

    double coef = 2.0 / n / (n - 1);

    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++) {
            prob[v[j] - v[i]] += coef;
        }

    vector<double> prob2(2*max);

    for (int i = 0; i < max; i++)
        for (int j = 0; j < max; j++)
            prob2[i+j] += prob[i] * prob[j];

    double ans = 0;
    double sum = 0;
    for (int i = 0; i < max; i++) {
        ans += sum * prob[i];
        sum += prob2[i];
    }

    printf("%.10f\n", ans);
    return 0;
}