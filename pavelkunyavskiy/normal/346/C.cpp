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

#define TASKNAME "C"

typedef long long ll;
typedef long double ld;

const int MAXN = 1100000;

int maxdiv[MAXN];
int dp[MAXN];

int x[MAXN];
int n;

vector<int> poss;


int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif
    
    scanf("%d",&n);

    for (int i = 0; i < n; i++)
        scanf("%d",&x[i]);
    sort(x, x + n);
    n = unique(x, x + n) - x;

    int a,b;

    scanf("%d %d",&a,&b);
    for (int j = 0; j <= a-b; j++)
        maxdiv[j] = 2;

    for (int i = 0; i < n; i++){
        for (int j = ((b+x[i]-1)/x[i])*x[i]; j <= a; j += x[i]){
//          assert(b <= j && j <= a);
  //        assert(j % x[i] == 0);
            maxdiv[j - b] = x[i];
        }
    }

    dp[a - b] = 0;
    poss.pb(-a);
    for (int i = a-1; i >= b; i--){
        int maxprev = i + maxdiv[i - b] - 1;
        int tmp = lower_bound(poss.begin(), poss.end(), -maxprev) - poss.begin();
        assert(tmp != (int)poss.size());
        assert(-poss[tmp] <= maxprev);
        dp[i - b] = dp[-poss[tmp] - b]+1;
//      eprintf("%d %d %d\n", i, maxprev, dp[i-b]);
        while (dp[-poss.back() - b] >= dp[i - b])
            poss.pop_back();
        poss.push_back(-i);
    }

    printf("%d\n", dp[0]);      
    TIMESTAMP(end);
    return 0;
}