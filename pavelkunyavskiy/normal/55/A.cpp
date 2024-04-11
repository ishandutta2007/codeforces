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

bool used[1100];

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int n;
    scanf("%d",&n);
    int x=0;
    for (int i=0;i<n+5;i++)
        for (int j=1;j<n;j++){
            used[x]=true;
            x=(x+j)%n;
        }
    used[x]=true;
    for (int i=0;i<n;i++)
        if (!used[i]){
            printf("NO\n");
            return 0;
        }
    printf("YES\n");
    
    return 0;
}