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

int a[5000];
int b[5000];

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int n,sum;
    cin>>n>>sum;
    for (int i=0;i<n;i++)
        cin>>a[i];
    b[n-1]=a[n-1];
    for (int i=n-2;i>=0;i--)
        b[i]=max(b[i+1],a[i]);
    int ans=0;
    for (int i=0;i<n;i++)
        ans=max(ans,(sum/a[i])*(b[i]-a[i]));        
    ans+=sum;
    cout<<ans<<endl;
    return 0;
}