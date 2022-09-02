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

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int a,b,m;
    cin >> a >> b >> m;

    ll tmp = (1000*1000*1000) % m;

    for (int i = 0; i < m && i <= a; i++){
        int tmp2 = (i*tmp) % m;
        if (tmp2 < (m - b) && tmp2){
            printf("1 %09d\n",i);
            return 0;
        }
    }

    printf("2\n");          
  return 0;
}