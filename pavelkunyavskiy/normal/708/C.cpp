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

const int MAXN = 410000;

vector<int> g[MAXN];
vector<int> sizes[MAXN];
int n;

int dfs(int v, int p = -1) {
    int size = 1;
    sizes[v].resize(g[v].size());
    int pid = -1;
    for (int i = 0; i < (int)g[v].size(); i++) {
        int u = g[v][i];
        if (u == p) {
            pid = i;
        } else {
            size += sizes[v][i] = dfs(u, v);
        }
    }
    if (pid != -1) {
        sizes[v][pid] = n - size;
    }
    return size;
}

vector<int> ans;

int dfs2(int v, int p, int rem) {
    int size = 1;
    for (int u : g[v]) {
        if (u != p)
            size += dfs2(u, v, rem);
    }
    if (n - size - rem <= n/2) {
        ans[v] = 1;
    }
    return size;
}

int main() {
#ifdef LOCAL
    assert(freopen(TASKNAME".in", "r", stdin));
    assert(freopen(TASKNAME".out", "w", stdout));
#endif

    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(0);

    int center = -1;
    for (int i = 0; i < n; i++) {
        if (*max_element(sizes[i].begin(), sizes[i].end()) <= n / 2) {
            center = i;
        }
    }
    assert(center != -1);
    ans.resize(n);
    ans[center] = 1;

    int maxv = 0, maxv2 = 0;
    for (int u : sizes[center]) {
        if (maxv < u) swap(maxv, u);
        if (maxv2 < u) swap(maxv2, u);
    }

    for (int i = 0; i < (int) g[center].size(); i++) {
        int cut = maxv;
        if (sizes[center][i] == maxv) {
            cut = maxv2;
        }
        if (2 * maxv == n) {
            cut = n / 2;
        }
        dfs2(g[center][i], center, cut);
    }
    for (int i = 0; i < n; i++)
        printf("%d%c", ans[i], " \n"[i == n - 1]);

    return 0;
}