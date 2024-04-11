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

const int MAXN = 101000;

vector<int> g[MAXN];
bool cap[MAXN];
bool used[MAXN];

bool have;
int size;

void dfs(int v) {
    if (used[v]) return;
    used[v] = true;
    size++;
    have |= cap[v];
    for (int u : g[v]) {
        dfs(u);
    }
}

int main() {
#ifdef LOCAL
    assert(freopen(TASKNAME".in", "r", stdin));
    assert(freopen(TASKNAME".out", "w", stdout));
#endif

    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < k; i++) {
        int x;
        scanf("%d", &x);
        cap[x - 1] = true;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int non_cap = 0;
    vector<int> sizes;
    for (int i = 0; i < n; i++) {
        if (used[i]) continue;
        have = false;
        size = 0;
        dfs(i);
        if (!have) {
            non_cap += size;
        } else {
            sizes.push_back(size);
        }
    }

    sort(sizes.begin(), sizes.end());
    sizes.back() += non_cap;

    long long ans = -m;
    for (int x : sizes) {
        ans += x * 1LL * (x - 1) / 2;
    }

    printf("%lld\n", ans);
    return 0;
}