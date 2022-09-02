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

ll cx[1111];
ll cy[1111];
int n,m;

int x,y;


int main(){
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

  scanf("%d %d",&n,&m);

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++){
        int t;
        scanf("%d",&t);
        cx[i] += t;
        cy[j] += t;
    }

  ll bestx = 1LL<<60;

  for (int i = 0; i <= n; i++){
    ll sum = 0;
    for (int j = 0; j < n; j++)
        sum += cx[j] * 1LL * ((4*j+2) - 4*i) * 1LL * ((4*j+2) - 4*i);
    if (bestx > sum){
        bestx = sum;
        x = i;
    }
  }



  ll besty = 1LL<<60;

  for (int i = 0; i <= m; i++){
    ll sum = 0;
    for (int j = 0; j < m; j++)
        sum += cy[j] * 1LL * ((4*j+2) - 4*i) * 1LL * ((4*j+2) - 4*i);
    if (besty > sum){
        besty = sum;
        y = i;
    }
  }

  cout << bestx + besty << endl << x <<" "<<y<<endl;

        

      
  return 0;
}