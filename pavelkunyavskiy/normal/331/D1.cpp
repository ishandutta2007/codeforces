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

const int dx[4] = {0,1,0,-1};
const int dy[4] = {1,0,-1,0};
const char name[4] = {'U','R','D','L'};

int pos[100][100][4];
int rdir[100][100];
int used[100][100][4], usedptr;
int n,b;

bool good(int x,int y){
    return 0 <= x && x <= b && 0 <= y && y <= b;
}


void go(int x,int y,int dir,ll t){
    ++usedptr;
    int id = 0;
    while (t > 0){
        if (rdir[x][y] != -1) dir = rdir[x][y];
        if (used[x][y][dir] == usedptr){
            t %= (id - pos[x][y][dir]);
            if (t == 0)
                break;
        }
        used[x][y][dir] = usedptr;
        pos[x][y][dir] = id++;
        if (good(x + dx[dir], y + dy[dir])){
            x += dx[dir];
            y += dy[dir];
        }
        --t;
    }
    printf("%d %d\n",x,y);
}



int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif

    memset(rdir,-1,sizeof(rdir));

    scanf("%d %d",&n,&b);

    for (int i = 0; i < n; i++){
       int x,y,x1,y1;
       scanf("%d %d %d %d",&x,&y,&x1,&y1);
       int dir = -1;
       for (int j = 0; j < 4; j++)
         if ((x1 - x) * dx[j] + (y1 - y) * dy[j] > 0)
            dir = j;
       while (x != x1 || y != y1){
          rdir[x][y] = dir;
          x += dx[dir];
          y += dy[dir];
       }
       rdir[x][y] = dir;
    }

    int q;
    scanf("%d",&q);

    for (int i = 0; i < q; i++){
        int x,y,dir=-1;char c;
        ll t;
        scanf("%d %d %c "LLD,&x,&y,&c,&t);
        for (int j = 0; j < 4; j++)
            if (name[j] == c)
                dir = j;
        go(x,y,dir,t);
    }

    
  TIMESTAMP(end);
  return 0;
}