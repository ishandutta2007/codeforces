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

const int MAXN = 300;
const int INF = 1 << 29;

int ans;

const int ITER = 11;

int g[ITER][MAXN][MAXN];

int a[MAXN][MAXN];
int b[MAXN][MAXN];
int n,m;

int main()
{
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

  scanf("%d",&n);


  for (int it = 0;it < ITER; it++)
      for (int i = 0; i < n; i++)
         for (int j = 0; j < n; j++)
            g[it][i][j] = INF*(i!=j);

  scanf("%d",&m);  

  for (int i = 0; i < m; i++){
    int a,b,c,d;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    --a,--b;
    g[0][a][b] = -c;
    g[0][b][a] = -d;
  }



  for (int it = 1; it < ITER; it++){
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            if (g[it-1][i][k] != INF)
                for (int j = 0; j < n; j++)
                    if (g[it-1][k][j] != INF)
                        g[it][i][j] = min(g[it][i][j],g[it-1][i][k] + g[it-1][k][j]);
  }

  bool ok = false;

  /*for (int i = 0; i < n; i++,cerr<<endl)
    for (int j = 0; j < n; j++)
        cerr << g[1][i][j] <<" ";
  cerr<<endl;
  for (int i = 0; i < n; i++,cerr<<endl)
    for (int j = 0; j < n; j++)
        cerr << g[2][i][j] <<" ";*/


  for (int i = 0; i < n; i++)
    if (g[ITER-1][i][i] < 0)
        ok = true;

  if (!ok){
    printf("0\n");
    return 0;
  }

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
        a[i][j] = INF*(i != j);

  int ans = 0;

  for (int it = ITER-1; it >= 0; it--){
     bool ok = false;

     for (int k = 0; k < n; k++)
         for (int i = 0; i < n; i++)
            if (a[i][k] != INF && g[it][k][i] != INF && a[i][k] + g[it][k][i] < 0){
                ok = true;
            }
     if (!ok){
        ans += (1<<it);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++){
                b[i][j] = INF;

                for (int k = 0; k < n; k++)
                    if (a[i][k] != INF && g[it][k][j] != INF)
                    b[i][j] = min(b[i][j], a[i][k] + g[it][k][j]);
            }

       for (int i = 0; i < n; i++)
          for (int j = 0; j < n; j++)
              a[i][j] = b[i][j];
     }
  }
        

  cout << ans+1 << endl;
  return 0;
}