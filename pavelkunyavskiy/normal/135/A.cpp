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

int a[111000];;

int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    if (a[n-1] != a[0] || a[0] != 1){
        printf("1");
        for (int i = 0; i < n-1; i++)
            printf(" %d",a[i]);
        printf("\n");    
    }
    else {
        a[n-1] = 2;
        for (int i = 0; i < n; i++)
            printf("%d ",a[i]);
        printf("\n");    
    }
  return 0;
}