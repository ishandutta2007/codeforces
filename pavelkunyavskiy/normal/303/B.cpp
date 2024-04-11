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

#define y1 y1_sdfagdafsag

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


ll x,y;
ll n,m;
ll a,b;

ll x1,y1,x2,y2;
ll ansdist;

void update(ll ncx,ll ncy){
    ll nx1 = ncx - a;
    ll nx2 = ncx + a;
    ll ny1 = ncy - b;
    ll ny2 = ncy + b;     
    if (nx1 % 2 || !(0 <= nx1 && nx1 <= n))
        return;
    if (nx2 % 2 || !(0 <= nx2 && nx2 <= n))
        return;

    if (ny1 % 2 || !(0 <= ny1 && ny1 <= m))
        return;
    if (ny2 % 2 || !(0 <= ny2 && ny2 <= m))
        return;

    ll dist = (x - ncx) * (x - ncx) + (y - ncy) * (y - ncy);

    if (ansdist != dist){
        if (ansdist < dist) return;
        ansdist = dist;
        x1 = nx1;
        x2 = nx2;
        y1 = ny1;
        y2 = ny2;
        return;
    }
    bool q = false;
    if (x1 != nx1)
        q = nx1 < x1;
    else if (y1 != ny1)
        q = ny1 < y1;
    else if (x2 != nx2)
        q = nx2 < x2;
    else if (y2 != ny2)
        q = ny2 < y2;

    if (q){
        x1 = nx1;
        x2 = nx2;
        y1 = ny1;
        y2 = ny2;
    }
}


int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif

    while (scanf(LLD" "LLD" "LLD" "LLD" "LLD" "LLD,&n,&m,&x,&y,&a,&b) == 6){
        ansdist = 0x7FFFFFFFFFFFFFFFLL;
        int _g = __gcd(a,b);
        a /= _g;
        b /= _g;
        ll coef = min(n/a,m/b);
        a *= coef, b *= coef;
        n *= 2, m *= 2;
        x *= 2, y *= 2;
        

        for (int i = 0; i < 3; i++){
            int X;
            if (i == 0) X = a;
            else if (i == 1) X = x;
            else X = n-a;

            for (int j = 0; j < 3; j++){
                int Y;
                if (j == 0) Y = b;
                else if (j == 1) Y = y;
                else Y = m-b;
                for (int dx = -5; dx <= 5; dx++)
                    for (int dy = -5; dy <= 5; dy++)
                        update(X+dx,Y+dy);
            }
        }
        printf(LLD" "LLD" "LLD" "LLD"\n",x1/2,y1/2,x2/2,y2/2);
    }
      
  TIMESTAMP(end);
  return 0;
}