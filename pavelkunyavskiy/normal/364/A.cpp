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

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

#define TASKNAME "A"

#ifdef LOCAL
static struct __timestamper {
    ~__timestamper(){
        TIMESTAMP(end);
    }
} __TIMESTAMPER;
#endif

typedef long long ll;
typedef long double ld;

int a;
char s[4100];

const int MAXSUM = 41000;

int cnt[MAXSUM];


int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif

    scanf("%d%s",&a, s);
    int n = strlen(s);
    for (int i = 0; i < n; i++){
        int sum = 0;
        for (int j = i; j < n; j++){
            sum += s[j] - '0';
            cnt[sum]++;
        }
    }

    if (a == 0){
        ll ans = 0;
        for (int i = 0; i < MAXSUM; i++)
           ans += 2 * cnt[i] * 1LL * cnt[0];
        ans -= cnt[0] * 1LL * cnt[0];
        printf(LLD"\n", ans);
        return 0;
    }
    ll ans = 0;
    for (int i = 1; i < MAXSUM; i++)
       if (a % i == 0 && (a / i < MAXSUM))
           ans += cnt[i] * 1LL * cnt[a / i];
    printf(LLD"\n", ans);
    return 0;
}