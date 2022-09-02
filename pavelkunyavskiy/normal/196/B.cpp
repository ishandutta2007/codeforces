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

char s[1550][1550];
int used[1550][1550];

int n,m;

const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,-1,0,1};

int smod(int x,int mod){
    return (x%mod+mod)%mod;
}

int sdiv(int x,int mod){
    return (x-smod(x,mod))/mod;
}

void dfs(int x,int y){
    int _x = smod(x,n);
    int _y = smod(y,m);
    if (s[_x][_y] == 'u'){
        if (used[_x][_y] == sdiv(x,n)*10000+sdiv(y,m))
            return;
        printf("Yes\n");
        exit(0);
    }
    s[_x][_y] = 'u';
    used[_x][_y] = sdiv(x,n)*10000+sdiv(y,m);

    for (int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (s[smod(nx,n)][smod(ny,m)] == '#')
            continue;
        dfs(nx,ny);
    }
}

int main(){
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif


  gets(s[0]);
  sscanf(s[0],"%d %d",&n,&m);


  for (int i = 0; i < n; i++)
    gets(s[i]);

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
        if (s[i][j] == 'S'){
            s[i][j] = '.';
            dfs(i,j);
            printf("No\n");
            return 0;
        }

  return 0;
}