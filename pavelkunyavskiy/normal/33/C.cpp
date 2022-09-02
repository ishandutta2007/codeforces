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
      

int a[110000];

int64 maxw[110000];
    
int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%d",&a[i]);   
    int64 cur=0;
    for (int i=0;i<n;i++){
            cur=cur+a[i];
            maxw[i]=max((i?maxw[i-1]:0LL),-cur);
        }
    cur=0;
    int64 best=maxw[n-1];            
    for (int i=n-1;i>=0;--i){
        cur+=a[i];
        best=max(best,-cur+(i?maxw[i-1]:0LL));
    }

    int64 ans=2*best;
    for (int i=0;i<n;i++)
        ans+=a[i];
    cout<<ans<<endl;
    return 0;
}