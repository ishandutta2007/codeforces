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

int color[1100][1100];

int cnt[2];
int n,m;

void dfs(int x,int y,int c){
    if (x < 0 || y < 0 || x >= n || y >= m)
        return;
    if (color[x][y] != -1){
        assert(color[x][y] == c);
        return;
    }
    color[x][y] = c;
    cnt[c]++;
    for (int i = -1; i <= 1; i+=2)
        for (int j = -1; j <= 1; j+=2){
            dfs(x+i,y+2*j,1-c);
            dfs(x+2*j,y+i,1-c);
        }
    return;
}

int main()
{
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    scanf("%d %d",&n,&m);
    memset(color,-1,sizeof(color));

    int ans = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
           if (color[i][j] == -1){
              cnt[0] = cnt[1] = 0;
              dfs(i,j,0);
              ans += max(cnt[0],cnt[1]);
           } 

    cout << ans << endl;
  return 0;
}