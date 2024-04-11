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


int g[510][510];
int deg[510];
int n;

char s[510];

void dfs(int v, char c) {
    if (s[v]) {
        if (s[v] == c) return;
        printf("No\n");
        exit(0);
    }
    s[v] = c;
    for (int i = 0; i < n; i++)
        if (g[v][i])
            dfs(i, 'a' ^ 'c' ^ c);
}

int main() {
#ifdef LOCAL
    assert(freopen(TASKNAME".in", "r", stdin));
    assert(freopen(TASKNAME".out", "w", stdout));
#endif

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        deg[i] = n - 1;
        for (int j = 0; j < n; j++) {
            g[i][j] = i != j;
        }
    }
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a, --b;
        deg[a]--;
        deg[b]--;
        g[a][b] = g[b][a] = 0;
    }

    for (int i = 0; i < n; i++) {
        if (s[i]) continue;
        if (deg[i] == 0) s[i] = 'b';
        else dfs(i, 'a');
    }

    eprintf("%s\n", s);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            bool need = abs(s[i] - s[j]) <= 1;
            if (g[i][j] == need) {
                eprintf("%d %d is wrong : %d %d\n", i, j, need, g[i][j]);
                printf("No\n");
                return 0;
            }
        }

    printf("Yes\n");
    puts(s);

    return 0;
}