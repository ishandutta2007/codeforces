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

#define TASKNAME "B"

typedef long long ll;
typedef long double ld;

int g[510][510]; 

int ord[510];
bool used[510];
ll ans[510];


int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif

    int n;
    scanf("%d",&n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d",&g[i][j]);

    
     for (int i = 0; i < n; i++)
        scanf("%d",&ord[i]),ord[i]--;

     for (int _k = n-1; _k >= 0; _k--){
        int k = ord[_k];

        used[k] = true;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);

        ll ans = 0;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (used[i] && used[j])
                    ans += g[i][j];

        ::ans[_k] = ans;
     }

     for (int i = 0; i < n; i++)
        printf(LLD"%c",ans[i]," \n"[i==n-1]);
      
  TIMESTAMP(end);
  return 0;
}