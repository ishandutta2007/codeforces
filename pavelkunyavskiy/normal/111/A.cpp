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

typedef long long int64;
typedef long double ld;

int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int64 n,x,y;
    cin >> n >> x >> y;
    if (y < n){
        printf("-1\n");
        return 0;
    }

    if ((y-n+1)*1LL*(y-n+1) + n - 1 < x){
        printf("-1\n");
        return 0;
    }

    for (int i = 0; i < n-1; i++)
        printf("1 ");
    cout << y-n+1 << endl;
    return 0;
}