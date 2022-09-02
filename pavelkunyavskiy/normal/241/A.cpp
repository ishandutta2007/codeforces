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


int m,k;
int d[1100];
int s[1100];

int main(){
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

    scanf("%d %d",&m,&k);
    for (int i = 0; i < m; i++)
        scanf("%d",&d[i]);
    for (int i = 0; i < m; i++)
        scanf("%d",&s[i]);

    int ms = 0;

    ll ans = 0;
    int cur = 0;

    for (int i = 0; i <= m; i++){
       cur -= d[i] - s[i];  
       ans += d[i];
       ms = max(ms,s[i]);
       while (cur < 0){
          ans += k;
          cur += ms;
       }
    }

    cout << ans << endl;      
    return 0;
}