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



const int inf = 1e9;

char s[30][30];
int dp[42][(1<<20)+10];
int n;
int lmasks[40][30];

int go(int sum, int mask){
    if (mask == 0)
        return inf;
//  int mask0 = mask; 
    int& res = dp[sum][mask];
    if (res > -10*n)
        return res;
    if (sum == 2*n-2)
        return res = 0;
    mask = (mask | (mask << 1));
    if (sum >= n-1) {
        mask >>= 1;
        mask &= ~(1 << (n - (sum - n) - 1));
    }
    res = -inf;
    for (int i = 0; i < 26; i++){
        int cres = -go(sum+1, mask & lmasks[sum+1][i]);
        if (i == !(sum % 2))
            cres++;
        if (i == (sum % 2))
            cres--;
        res = max(res, cres);
    }
//  eprintf("%d %d[%d] -> %d\n", sum, mask0, mask,res);
    return res;
}
                          
int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif

    memset(dp, 0x80, sizeof(dp));

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf(" %c",&s[i][j]);

    
    for (int sum = 0; sum <= 2*n-2; sum++)
        for (int c = 0; c < 26; c++){
            int& mask = lmasks[sum][c];
            mask = 0;
            for (int i = n-1; i >= 0; i--){
                int j = sum - i;
                if (j < 0 || j >= n) continue;
                mask = (mask << 1);
                if (s[i][j] == c+'a')
                    mask |= 1;
            }
        }
    



    int bal = -go(0,1);
//  eprintf("%d\n", bal);

    if (s[0][0] == 'a') bal++;
    if (s[0][0] == 'b') bal--;

    if (bal > 0)
        puts("FIRST");
    else if (bal == 0)
        puts("DRAW");
    else
        puts("SECOND");
      
    return 0;
}