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

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

#define TASKNAME "C"

typedef long long ll;
typedef long double ld;

const int MAXN = 1000010;

int v[MAXN][6];
int sz[MAXN];
                                 
int a[5100];
int used[MAXN];


int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif
    
    int n,k;
    scanf("%d %d",&n,&k);
    int usedptr = 0;
    for (int i = 0; i < n; i++){
        scanf("%d",&a[i]);
        usedptr++;
        for (int j = 0; j < i; j++){
            int diff = abs(a[i] - a[j]);
            if (used[diff] != usedptr && sz[diff] <= k)
                v[diff][sz[diff]++]=i,used[diff] = usedptr;
        }
    }
                    
                             
    for (int i = 1; i < MAXN; i++){
        int cnt = 0;
        ++usedptr;
        for (int j = i; j < MAXN && cnt <= k; j += i){
            for (int t = 0; t < sz[j]; t++){
                int tmp = v[j][t];
                if (used[tmp] != usedptr)
                    used[tmp] = usedptr, cnt++;
            }

        }
        eprintf("%d %d\n",cnt,k);
        if (cnt <= k){
            printf("%d\n",i);
            return 0;
        }       
    }

    assert(false);

      
    TIMESTAMP(end);
    return 0;
}