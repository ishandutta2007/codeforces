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
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    for (int i=0;i<k;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        if (x<=5 || y<=5 || x>=n-4 || y>=m-4){
            printf("YES\n");
            return 0;
        }   
    }
    printf("NO\n");
    return 0;
}