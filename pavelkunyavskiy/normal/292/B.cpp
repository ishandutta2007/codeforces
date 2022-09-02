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


int d[110000];
int n,m;

int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif
    scanf("%d %d",&n,&m);

    for (int i = 0; i < m; i++){
        int a,b;
        scanf("%d %d",&a,&b);
        --a,--b;
        d[a]++;
        d[b]++;
    }

    sort(d,d+n);

    if (d[n-2] == 1 && d[n-1] == n-1)
        printf("star topology\n");
    else if (d[0] == 2 && d[n-1] == 2)
        printf("ring topology\n");
    else if (d[0] == 1 && d[1] == 1 && d[2] == 2 && d[n-1] == 2)
        printf("bus topology\n");
    else
        printf("unknown topology\n");

      
    TIMESTAMP(end);
    return 0;
}