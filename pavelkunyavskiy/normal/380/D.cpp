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

const int MOD = 1000000007;
const int MAXN = 110000;

int pow(int a,int b){
    if (!b) return 1;
    if (b & 1) return (pow(a, b - 1) * 1LL * a) % MOD;
    int temp = pow(a, b / 2);
    return (temp * 1LL * temp) % MOD;
}

int f[MAXN];
int invf[MAXN];

int cnk(int n, int k){
    if (k > n) return 0;
    return ((f[n] * 1LL * invf[k]) % MOD * invf[n - k]) % MOD;
}

void initf(){
    f[0] = invf[0] = 1;
    for (int i = 1; i < MAXN; i++){
        f[i] = (f[i-1] * 1LL * i) % MOD;
        invf[i] = pow(f[i], MOD - 2);
    }
}





int main(){
  #ifdef LOCAL
    assert(freopen(TASKNAME".in","r",stdin));
    assert(freopen(TASKNAME".out","w",stdout));
  #endif

    initf();
    int n;
    scanf("%d", &n);
    vector<pair<int, int> > used;
    for (int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        if (x) used.pb(mp(x - 1, i));
    }
    sort(used.begin(), used.end());
    reverse(used.begin(), used.end());
    int l = 0;
    int r = n-1;

    ll ans = 1;

    for (int i = 0; i < (int)used.size() && ans != 0; i++){
        int id = used[i].second;
//      eprintf("%d %d [%d..%d]\n", used[i].first, used[i].second, l, r);
        if (!(l <= id && id <= r)) {
            printf("0\n");
            return 0;
        }
        int more = (n - used[i].first - 1) - (n - (r - l + 1));
//      eprintf("%d\n", more);
        if (i == (int)used.size() - 1) {
            ans = (ans * 1LL * (cnk(more, id - l) + (used[i].first == 0 ? 0 : cnk(more, r - id)))) % MOD;
            l = id + 1;
            r = l + used[i].first - 1;
        }
        else if (used[i+1].second > used[i].second) {
            ans = (ans * 1LL * cnk(more, id - l)) % MOD;
            l = id + 1;
            r = l + used[i].first - 1;
        } else {
            ans = (ans * 1LL * cnk(more, r - id)) % MOD;
            r = id - 1;
            l = r - used[i].first + 1;
        }
    }


    if (l <= r)
        ans = (ans * 1LL * pow(2, r - l)) % MOD;

    printf("%d\n", (int)(ans % MOD));      
    return 0;
}