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

#define TASKNAME "D"

typedef long long ll;
typedef long double ld;

int n,m;

int a[1010][1010];

int used[1010][1010];
int usedptr;


bool check(int val){
    ++usedptr;
    for (int i = 0; i < n; i++){
        vector<int> good;
        for (int j = 0; j < m; j++)
            if (a[i][j] >= val)
                good.pb(j);

        int sz = good.size();
        for (int j = 0; j < sz; j++)
            for (int k = j+1; k < sz; k++){
                if (used[good[j]][good[k]] == usedptr)
                    return true;
                used[good[j]][good[k]] = usedptr;
            }
    }
    return false;
}

int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif
    scanf("%d %d",&n,&m);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d",&a[i][j]);

    int L = 0;
    int R = 1000000001;

    while (R - L > 1){
        int mid = (L + R) / 2;
        if (check(mid))
            L = mid;
        else
            R = mid;
    }

    printf("%d\n",L);

      
    TIMESTAMP(end);
    return 0;
}