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


int n,m;
ll h[110000];
ll p[110000];

bool check(ll t){
    int r = 0;
    for (int i = 0; i < n && r < m; i++){
        int tmp = r;
        while (r < m && p[r] - p[tmp] + min(abs(h[i] - p[tmp]), abs(p[r] - h[i])) <= t) 
            r++;
    }
    return r == m;
}

int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif
  while (scanf("%d %d",&n,&m) == 2){

    for (int i = 0; i < n; i++)
        scanf(LLD,&h[i]);
    for (int i = 0; i < m; i++)
        scanf(LLD,&p[i]);


    ll lf = -1;
    ll rg = 1e12;

    while (rg - lf > 1){
        ll mid = (lf + rg) / 2;
        if (check(mid))
            rg = mid;
        else
            lf = mid;
    }   
    printf(LLD"\n", rg);
  }
      
  TIMESTAMP(end);
  return 0;
}