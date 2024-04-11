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

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    
    int minsum = 1<<30;
    int n;
    cin >> n;

    for (int i = 0; i <= n; i++){
        int x = n - 4*i;
        if (x >= 0 && x%7 == 0)
            minsum = min(minsum,i + x/7);
    }

    if (minsum == (1<<30)){
        cout << -1 << endl;
        return 0;
    }

    for (int i = n; i >= 0; --i){
        int x = n - 4*i;

        if (x >= 0 && x%7 == 0 && (i + x/7 == minsum)){
            for (int j = 0; j < i; j++)
                printf("4");
            for (int j = 0; j < x/7; j++)
                printf("7");
            printf("\n");
            return 0;            
        }            
    }     
    return 0;
}