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


int g[65][65][65];

int d[65][65][65];
int n,m,r;


int main(){
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

  scanf("%d %d %d",&n,&m,&r);

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++)
      for (int k = 0; k < n; k++)
        scanf("%d",&g[i][j][k]);

    for (int l = 0; l < n; l++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                g[i][j][k] = min(g[i][j][k],g[i][j][l] + g[i][l][k]);

    /*for (int j = 0; j < n; j++,cerr<<endl)
        for (int k = 0; k < n; k++)
            cerr << g[i][j][k] <<" ";
    cerr<<endl;*/
  }

  for (int k = 0; k < n; k++)
      for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            d[k][i][j] = (1<<29)*(i!=j);


  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++){
        d[1][i][j] = (1<<29)*(i != j);

        for (int k = 0; k < m; k++)
            d[1][i][j] = min(d[1][i][j], g[k][i][j]);
    }


  for (int i = 2; i < n; i++)
    for (int j = 0; j < n; j++)
        for (int k = 0; k < n; k++)
            for (int l = 0; l < n; l++)
                d[i][j][k] = min(d[i][j][k], d[i-1][j][l] + d[1][l][k]);



  for (int i = 0; i < r; i++){
    int s,t,cnt;
    scanf("%d %d %d",&s,&t,&cnt);
    printf("%d\n",d[min(cnt+1,n-1)][s-1][t-1]);     
  }

  return 0;
}