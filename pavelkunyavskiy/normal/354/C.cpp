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

#ifdef LOCAL
static struct __timestamper {
    ~__timestamper(){
        TIMESTAMP(end);
    }
} __TIMESTAMPER;
#endif

typedef long long ll;
typedef long double ld;

const int MAXN = 1100000;

int cnt[MAXN];
int sums[MAXN];
int n,k;

int getcnt(int l,int r){
    return sums[min(MAXN-1, r)] - (l ?  sums[min(MAXN-1,l-1)] : 0);
}

bool can(int d){
    if (d == 1) return true;
    if (getcnt(1, d-1)) return false;
    if (k+1 > d-1) return true;

    for (int i = d; i < MAXN; i += d)
        if (getcnt(i + k + 1, i + d - 1)){
            eprintf("FAIL : [%d, %d]\n", i+k+1, i+d-1);
            return false;
        }
    return true;                         
}


int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif

    scanf("%d %d",&n,&k);
    for (int i = 0; i < n; i++){
        int x;
        scanf("%d",&x);
        cnt[x]++;
    }

    for (int i = 1; i < MAXN; i++)
        sums[i] = sums[i-1] + cnt[i];


    for (int d = MAXN; d >= 1; d--){
        if (can(d)) {
            printf("%d\n", d);
            return 0;
        }
    }

      
  return 0;
}