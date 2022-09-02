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
      
int n,m;
int a[1000];
    
int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    scanf("%d %d",&n,&m);
    for (int i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    int ans=0;
    for (int i=0;i<m;i++)
        ans-=(a[i]*(a[i]<0));
    cout<<ans<<endl;
    return 0;
}