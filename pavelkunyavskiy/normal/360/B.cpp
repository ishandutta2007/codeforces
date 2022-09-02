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

#define TASKNAME "B"

#ifdef LOCAL
static struct __timestamper {
    ~__timestamper(){
        TIMESTAMP(end);
    }
} __TIMESTAMPER;
#endif

typedef long long ll;
typedef long double ld;


const int MAXN = 2100;

int a[MAXN];
int dp[MAXN];
int n,k;

int check(int maxv){
    for (int i = 0; i < n; i++){
        dp[i] = i;
        for (int j = 0; j < i; j++)
            if (abs(a[j] - a[i]) <= maxv * 1LL* (i - j))
                dp[i] = min(dp[i], dp[j] + i - j - 1);
//      eprintf("%d\n", dp[i]);
    }

    for (int i = 0; i < n; i++)
        if (dp[i] + (n - i - 1) <= k)
            return true;
    return false;
}

int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif

    scanf("%d%d",&n,&k);

    int cur = 0;

    for (int i = 0; i < n; i++){
        scanf("%d",&a[i]);
        if (i) cur = max(cur, abs(a[i] - a[i-1]));
    }

//    check(1);
//    return 0;

    int l = -1;
    int r = cur;


    while (r - l > 1){
        int mid = l + (r - l) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid;
    }

    printf("%d\n", r);      
    return 0;
}