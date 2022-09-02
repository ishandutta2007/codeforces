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


int g[200][200];

int main(){
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
                
  int n,k;
  cin >> k;
  n = 0;
              
  for (int i = 100; i >= 3; i--){
    if (i*(i-1)*(i-2)/6 <= k){
        
        for (int j = n; j < n+i; j++)
           for (int t = n; t < n+i; t++)
            if (j != t)
                g[j][t] = 1;
        n += i;
        k -= i*(i-1)*(i-2)/6;
        if (k == 0)
            break;
        n++;
        for (int j = 0; j < n-1; j++){
            if (k >= j){
                g[n-i+j-1][n-1] = g[n-1][n-i+j-1] = 1;
                k -= j;
            }
            else
                break;
        }
        if (k == 1){                 
            g[n][n-i-1] = g[n-i-1][n] = 1;
            g[n][n-i] = g[n-i][n] = 1;
            n++;
            k--;
        }
        i++;
    }
  }

  //assert(n <= 100);

  printf("%d\n",n);

  for (int i = 0; i < n; i++,printf("\n"))
    for (int j = 0; j < n; j++)
        printf("%d",g[i][j]);         
  return 0;
}