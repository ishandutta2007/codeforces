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


char s[510][510];
bool added[510][510];
int comp[510][510];
int compid;
vector<int> compsz;
int n, k;

bool good(int i, int j) {
    return 0 <= i && i < n && 0 <= j && j < n;
}

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

void dfs(int x, int y, int cid) {
    if (!good(x, y) || s[x][y] != '.') {
        return;
    }
    if (comp[x][y] == -1) {
        comp[x][y] = cid;
        compsz[cid]++;
    } else {
        return;
    }
    for (int i = 0; i < 4; i++) {
        dfs(x + dx[i], y + dy[i], cid);
    }
}

vector<int> compcnt;
int answer;
int current;

void add(int x, int y) {
    if (!good(x, y)) return;
    assert(!added[x][y]);
    added[x][y] = 1;
    if (s[x][y] == '.') {
        int c = comp[x][y];
        compcnt[c]++;
        if (compcnt[c] == 1) {
            current += compsz[c];
        }
    }
}

void remove(int x, int y) {
    if (!good(x, y)) return;
    assert(added[x][y]);
    added[x][y] = 0;
    if (s[x][y] == '.') {
        int c = comp[x][y];
        compcnt[c]--;
        if (compcnt[c] == 0) {
            current -= compsz[c];
        }
    }
}

void dump() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            eprintf("%c", ".#"[added[i][j]]);
        }
        eprintf("\n");
    }
    eprintf("\n");
}

int main() {
#ifdef LOCAL
    assert(freopen(TASKNAME".in", "r", stdin));
    assert(freopen(TASKNAME".out", "w", stdout));
#endif

    scanf("%d%d", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }

    memset(comp, -1, sizeof(comp));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i][j] == '.' && comp[i][j] == -1) {
                int id = (int) compsz.size();
                compsz.push_back(0);
                dfs(i, j, id);
            }
        }
    }

    compcnt.resize(compsz.size());
    if (!compsz.empty()) {
        answer = *max_element(compsz.begin(), compsz.end());
    }

    for (int i = 0; i + k <= n; i++) {
        for (int j = -1; j <= k; j++) {
            for (int q = 0; q <= k; q++) {
                add(i + j, q);
            }
        }
        for (int j = 0; j < k; j++){
            for (int q = 0; q < k; q++) {
                if (s[i + j][q] != '.') {
                    current++;
                }
            }
        }
        remove(i + k, k);
        remove(i - 1, k);
        answer = max(answer, current);

        for (int j = 0; j + k < n; j++) {
            remove(i - 1, j);
            remove(i + k, j);
            add(i - 1, j + k);
            add(i + k, j + k);
            for (int q = 0; q < k; q++) {
                remove(i + q, j - 1);
                add(i + q, j + k + 1);
                if (s[i + q][j] != '.') current--;
                if (s[i + q][j + k] != '.') current++;
            }
            answer = max(answer, current);
        }

        for (int j = 0; j <= n; j++) {
            for (int q = 0; q <= n; q++) {
                if (added[j][q]) {
                    remove(j, q);
                }
            }
        }
        current = 0;
    }

    printf("%d\n", answer);

    return 0;
}