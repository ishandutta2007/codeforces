#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <iterator>
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
      
int a[10000];
    
int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int n;
    for (int i=0;;i++){
        int tmp=scanf("%d,",&a[i]);
        if (tmp!=1){
           n=i; 
           break;
        }        
    }
    sort(a,a+n);
    n=unique(a,a+n)-a;
    for (int i=0;i<n;){
        int j=i;
        for (;j<n && (i==j || a[j]==a[j-1]+1);j++);
        if (i==j-1)
            printf("%d%c",a[i],",\n"[j==n]);
        else
            printf("%d-%d%c",a[i],a[j-1],",\n"[j==n]);
        i=j;
    }
    return 0;
}