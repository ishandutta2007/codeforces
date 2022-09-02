#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>
#define mp make_pair
#define pb push_back                     
#define setval(a,v) memset(a,v,sizeof(a))

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

typedef long long ll;
typedef long double ld;

int main()
{
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int n,m,x1,y1,x2,y2;
    cin >> n >> m >> x1 >> y1 >> x2 >> y2;
    int dx = abs(x1 - x2);
    int dy = abs(y1 - y2);

    if ((dx < 4 && dy < 4) || (min(dx,dy) <= 2 && max(dx,dy) <= 4))
        printf("First\n");
    else
        printf("Second\n");
  return 0;
}