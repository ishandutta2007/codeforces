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

const int MOD = 1000000007;
const int MAXN = 1100000;

int sum[MAXN];
map<int,int> last;

int bit[MAXN];

void update(int pos,int val){
    for (; pos < MAXN; pos = pos | (pos+1))
        bit[pos] = (bit[pos] + val) % MOD;
}

int get(int pos){
    int ans = 0;
    for (; pos >= 0; pos = (pos & (pos + 1)) - 1)
        ans = (ans + bit[pos]) % MOD;
    return ans;
}

int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif
    int n;
    scanf("%d",&n);

    int cur = 0;

    for (int i = 0; i < n; i++){
        int a;
        scanf("%d",&a);
        int res = get(a) - ((last.find(a) == last.end())?-1:sum[last[a]]);
        res = (res + MOD) % MOD;
        res = (res * 1LL * a) % MOD;
        sum[i] = get(a);
//          eprintf("%d %d %d\n",i,res,sum[i]);
        cur = (cur + res) % MOD;
        update(a,res);
        last[a] = i;
    }

    printf("%d\n",cur);

      
    TIMESTAMP(end);
    return 0;
}