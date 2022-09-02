#include <iostream>
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

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

#define TASKNAME "A"

typedef long long ll;
typedef long double ld;

const int MAXN = 110000;

int a[MAXN];


int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
        scanf("%d",&a[i]);

    ll curh = 0;
    int m;
    scanf("%d",&m);
    for (int i = 0; i < m; i++){
        int h,w;
        scanf("%d %d",&w,&h);
        ll tmp = max((ll)a[w-1], curh);
        printf("%lld\n",tmp);
        curh = tmp + h;
    }

      
    return 0;
}