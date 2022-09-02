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

int g[110][110];

int x[110];
int y[110];
int a[110];


int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif

    int n,d;
    scanf("%d %d",&n,&d);
    for (int i = 1; i < n - 1; i++)
        scanf("%d",&a[i]);

    for (int i = 0; i < n; i++)
        scanf("%d %d",&x[i],&y[i]);


    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i != j) {
                g[i][j] = (abs(x[i] - x[j]) + abs(y[i] - y[j])) * d - a[j];
            } else
                g[i][j] = 0;

/*  for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            eprintf("%04d%c",g[i][j]," \n"[j==n-1]);*/

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                g[i][j] = min(g[i][j],g[i][k] + g[k][j]);

    printf("%d\n",g[0][n-1]);
      
    TIMESTAMP(end);
    return 0;
}