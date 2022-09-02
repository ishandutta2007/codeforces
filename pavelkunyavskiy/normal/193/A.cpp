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


bool used[51][51];
char c[51][51];
int n,m;


void dfs(int x,int y){
    if (x < 0 || y < 0 || x >= n || y >= m)
        return;
    if (used[x][y] || c[x][y] == '.') 
        return;
    used[x][y] = true;
    dfs(x+1,y);
    dfs(x,y+1);
    dfs(x-1,y);
    dfs(x,y-1);
}


bool check(){
    memset(used,0,sizeof(used));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (c[i][j] == '#'){
                dfs(i,j);

                for (int i = 0; i < n; i++)
                    for (int j = 0; j < m; j++)
                     if (c[i][j] == '#' && !used[i][j])
                            return true;
                return false;
            }

    return false;
            
}

int main(){
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
  scanf("%d %d",&n,&m);
  int cnt = 0;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
        scanf(" %c",&c[i][j]);
        cnt += (c[i][j] == '#');
    }
  }

  if (cnt <= 2)
  {
    printf("-1\n");
    return 0;
  }


  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
        if (c[i][j] == '#'){
            c[i][j] = '.';
            if (check()){
                printf("1\n");
                return 0;
            }
            c[i][j] = '#';
        }

  printf("2\n");
  return 0;
}