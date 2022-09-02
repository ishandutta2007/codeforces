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

ll bit[4][1010][1010];
int n;


void update(int x,int y,ll v, int id){
    for (int i = x; i < n; i = (i | (i+1)))
    for (int j = y; j < n; j = (j | (j+1))){
        bit[id][i][j] ^= v;
    }
}

void update(int x, int y,ll v){
    if (!(y & 1) && !(x & 1))  update(x, y, v, 0);
    if (!(y & 1)) update(x, y, v, 1);
    if (!(x & 1)) update(x, y, v, 2);
    update(x, y, v, 3);
}

void updateSquare(int xl, int yl, int xr,int yr, ll v){
    update(xl, yl, v);
    update(xr, yl, v);
    update(xl, yr, v);
    update(xr, yr, v);
}

ll get(int x,int y, int id){
    ll v = 0;
    for (int i = x; i >= 0; i = (i & (i+1))-1)
    for (int j = y; j >= 0; j = (j & (j+1))-1){
        v ^= bit[id][i][j];
    }
    return v;
}

ll get(int x, int y){
    ll v = 0;
    v ^= get(x, y, 0);
    if (x & 1) v ^= get(x, y, 1);
    if (y & 1) v ^= get(x, y, 2);
    if ((x & 1) && (y & 1)) v ^= get(x, y, 3);
//  eprintf("%d %d "LLD"\n", x,y,v);
    return v;
}

ll getSquare(int xl, int yl, int xr,int yr){
    ll v = 0;
    v ^= get(xl, yl);
    v ^= get(xr, yl);
    v ^= get(xl, yr);
    v ^= get(xr, yr);
    return v;
}



int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif

  int m;
  scanf("%d %d",&n,&m);

  for (int i = 0; i < m; i++){
     int ty;
     scanf("%d",&ty);
     int x0, y0, x1, y1;
     scanf("%d%d%d%d",&x0,&y0,&x1,&y1);
     if (ty == 2){
        ll v;
        scanf(LLD,&v);
        updateSquare(x0-1,y0-1,x1,y1,v);
     } else {
        printf(LLD"\n", getSquare(x0-2,y0-2,x1-1,y1-1));
     }
  }
/*  eprintf("\n");

  for (int i = 0; i < 4; i++)
  {
     for (int j = 0; j < n; j++)
        for (int k = 0; k < n; k++)
            eprintf(LLD"%c", bit[i][j][k]," \n"[k==n-1]);
     eprintf("\n");
  }*/
      
  TIMESTAMP(end);
  return 0;
}