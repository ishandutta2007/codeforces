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


bool used[201][201][201];

string ans;

void go(int a, int b, int c) {
    if (used[a][b][c]) return;
    used[a][b][c] = 1;
    if (a + b + c == 1) {
        ans += "RGB"[b + 2 * c];
        return;
    }
    if (a >= 2) go(a - 1, b, c);
    if (b >= 2) go(a, b - 1, c);
    if (c >= 2) go(a, b, c - 1);
    if (a >= 1 && b >= 1) go(a - 1, b - 1, c + 1);
    if (b >= 1 && c >= 1) go(a + 1, b - 1, c - 1);
    if (c >= 1 && a >= 1) go(a - 1, b + 1, c - 1);
}

int main() {
#ifdef LOCAL
    assert(freopen(TASKNAME".in", "r", stdin));
    assert(freopen(TASKNAME".out", "w", stdout));
#endif

    int a[3], n;
    memset(a, 0, sizeof(a));
    scanf("%d",&n);

    for (int i = 0; i < n; i++) {
        char x;
        scanf(" %c", &x);
        if (x == 'R') a[0]++;
        else if (x == 'G') a[1]++;
        else if (x == 'B') a[2]++;
    }
    go(a[0], a[1], a[2]);
    sort(ans.begin(), ans.end());
    printf("%s\n", ans.c_str());
    return 0;
}