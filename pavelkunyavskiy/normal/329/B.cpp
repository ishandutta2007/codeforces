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

#define TASKNAME "B"

typedef long long ll;
typedef long double ld;

int n,m;
char s[1010][1010];
int d[1010][1010];


const int dx[4] = {0,1,0,-1};
const int dy[4] = {-1,0,1,0};


int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif
    gets(s[0]);
    sscanf(s[0],"%d %d",&n,&m);
    for (int i = 0; i < n; i++)
        gets(s[i]);

    int x,y;
    x = y = -1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (s[i][j] == 'E')
                x = i, y = j;

    assert(x != -1);
    memset(d,0x3f,sizeof(d));

    d[x][y] = 0;
    queue<int> qx,qy;
    qx.push(x), qy.push(y);

    while (!qx.empty()){
        int x = qx.front(); qx.pop();
        int y = qy.front(); qy.pop();
        for (int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m && s[nx][ny] != 'T' && d[nx][ny] > d[x][y] + 1){
                d[nx][ny] = d[x][y] + 1;
                qx.push(nx);
                qy.push(ny);
            }
        }
    }

    x = y = -1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (s[i][j] == 'S')
                x = i, y = j;

    assert(x != -1);
    
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (isdigit(s[i][j]) && d[i][j] <= d[x][y])
                ans += s[i][j] - '0';

    printf("%d\n", ans);

  
    TIMESTAMP(end);
    return 0;
}