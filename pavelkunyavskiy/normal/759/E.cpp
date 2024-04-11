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

#define TASKNAME "E"

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

const int MOD = 1000000007;

void add(int& a, int b) {
    if ((a += b) >= MOD) a -= MOD;
}

int mul(int a, int b) {
    return (int) ((a * 1LL * b) % MOD);
}


struct BigInt {
    static const int BASE = 1000000000;
    vector<int> v;

    void read() {
        static char s[10010];
        scanf("%s", s);
        int len = strlen(s);
        v.push_back(0);
        int cur = 1;
        for (int i = len - 1; i >= 0; i--) {
            if (cur == BASE) {
                v.push_back(0);
                cur = 1;
            }
            v.back() += cur * (s[i] - '0');
            cur = cur * 10;
        }
    }

    int divide(int x) {
        int rem = 0;
        for (int i = (int)v.size() - 1; i >= 0; i--) {
            ll cur = (rem * 1LL * BASE + v[i]);
            v[i] = (int) (cur / x);
            assert(v[i] <= BASE);
            rem = (int) (cur % x);
        }
        while (v.size() > 1 && v.back() == 0) {
            v.pop_back();
        }
        return rem;
    }
};

vector<int> rems;
vector<int> d;
vector<int> b;

int n;

const int MAXN = 310000;

int dp[MAXN];
int ndp[MAXN];


int main() {
#ifdef LOCAL
    assert(freopen(TASKNAME".in", "r", stdin));
    assert(freopen(TASKNAME".out", "w", stdout));
#endif

    scanf("%d", &n);
    d.resize(n - 1);
    for (int &x : d) {
        scanf("%d", &x);
    }
    b.resize(n);
    for (int &x : b) {
        scanf("%d", &x);
    }
    BigInt M;
    M.read();

    rems.resize(n - 1);

    for (int i = 0; i < n - 1; i++) {
        if (d[i] != 1) {
            rems[i] = M.divide(d[i]);
        } else {
            rems[i] = 0;
        }
    }

    if (M.v.size() > 1 || M.v[0] >= MAXN) {
        printf("0\n");
        return 0;
    }
    rems.push_back(M.v[0]);

    dp[0] = 1;
    int maxv = 0;

    for (int i = 0; i < n; i++) {
        maxv += b[i];

        ndp[0] = dp[0];

        for (int j = 1; j <= maxv; j++) {
            ndp[j] = ndp[j - 1];
            add(ndp[j], dp[j]);
            if (j > b[i]) {
                add(ndp[j], MOD - dp[j - b[i] - 1]);
            }
        }
        if (i != n - 1) {
            int cnt = 0;
            for (int j = rems[i]; j <= maxv; j += d[i]) {
                dp[cnt++] = ndp[j];
            }
            for (int j = cnt; j <= maxv; j++) {
                dp[j] = 0;
            }
            maxv /= d[i];
        }
    }

    printf("%d\n", ndp[rems.back()]);


    return 0;
}