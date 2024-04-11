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

//#define DEBUG

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

#ifdef DEBUG
int m[1000][1000];
#endif

void work(vector<int>& ans, vector<int> q, vector<int> u) {
    if (q.empty()) return;
    printf("%d\n", (int) q.size());
    for (int x : q) {
        printf("%d ", x);
    }
    printf("\n");
    fflush(stdout);
    vector<int> res(ans.size());
#ifdef DEBUG
    for (int i = 0; i < (int)ans.size(); i++) {
        res[i] = (int) 1.1e9;
        for (int j : q) {
            res[i] = min(res[i], m[i][j - 1]);
        }
    }
#else
    for (int i = 0; i < (int)ans.size(); i++) {
        scanf("%d", &res[i]);
    }
#endif
    for (int x : u) {
        ans[x - 1] = min(ans[x - 1], res[x - 1]);
    }
}

int main() {
#ifdef DEBUG
    freopen("B.in", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
#ifdef DEBUG
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &m[i][j]);
        }
    }
#endif
    vector<int> ans(n, (int) 1.1e9);
    for (int bit = 0; bit < 10; bit++) {
        vector<int> on, off;
        for (int i = 1; i <= n; i++) {
            if (i & (1 << bit)) {
                on.push_back(i);
            } else {
                off.push_back(i);
            }
        }
        work(ans, on, off);
        work(ans, off, on);
    }

    printf("-1\n");
    for (int x : ans) {
        printf("%d ", x);
    }
    printf("\n");
    fflush(stdout);

    return 0;
}