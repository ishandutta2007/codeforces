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

const int MAXN = 1000100;

int n, cost_change, cost_remove;
int v[MAXN];
int cost[MAXN];
long long dp[MAXN][3];

void factor(int a, vector<int>& p) {
    for (int i = 2; i * i <= a; i++) {
        if (a % i == 0) {
            p.push_back(i);
            while (a % i == 0) a /= i;
        }
    }
    if (a != 1) p.push_back(a);
}

const long long INF = (long long)1e18;

long long solve() {
    if (cost[0] == 2 && cost[n-1] == 2) return INF;
    dp[0][0] = 0;
    dp[0][1] = INF;
    dp[0][2] = INF;
    for (int i = 0; i < n; i++) {
        if (cost[i] == 0) {
            dp[i+1][0] = dp[i][0];
            dp[i+1][1] = min(dp[i][1] + cost_remove, dp[i][0] + cost_remove);
            dp[i+1][2] = min(dp[i][2], dp[i][1]);
        } else if (cost[i] == 1) {
            dp[i+1][0] = dp[i][0] + cost_change;
            dp[i+1][1] = min(dp[i][1] + cost_remove, dp[i][0] + cost_remove);
            dp[i+1][2] = min(dp[i][2] + cost_change, dp[i][1] + cost_change);
        } else if (cost[i] == 2) {
            dp[i+1][0] = INF;
            dp[i+1][1] = min(dp[i][1] + cost_remove, dp[i][0] + cost_remove);
            dp[i+1][2] = INF;
        }
        dp[i+1][0] = min(dp[i+1][0], INF);
        dp[i+1][1] = min(dp[i+1][1], INF);
        dp[i+1][2] = min(dp[i+1][2], INF);
    }
    return min(min(dp[n][0], dp[n][1]), dp[n][2]);
}

int main() {
#ifdef LOCAL
    assert(freopen(TASKNAME".in", "r", stdin));
    assert(freopen(TASKNAME".out", "w", stdout));
#endif

    scanf("%d%d%d", &n, &cost_remove, &cost_change);

    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    vector<int> primes;
    factor(v[0], primes);
    factor(v[0]-1, primes);
    factor(v[0]+1, primes);
    factor(v[n-1], primes);
    factor(v[n-1]-1, primes);
    factor(v[n-1]+1, primes);

    sort(primes.begin(), primes.end());
    primes.erase(unique(primes.begin(), primes.end()), primes.end());

    long long ans = INF;

    for (int p : primes) {
        for (int i = 0; i < n; i++) {
            if (v[i] % p == 0) cost[i] = 0;
            else if ((v[i] + 1) % p == 0 || (v[i] - 1) % p == 0) cost[i] = 1;
            else cost[i] = 2;
        }
        ans = min(ans, solve());
    }

    printf(LLD"\n", ans);

    return 0;
}