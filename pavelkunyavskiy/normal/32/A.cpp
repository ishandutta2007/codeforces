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

int a[1100];
int d;

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int n;
    scanf("%d %d",&n,&d);
    for (int i=0;i<n;i++)
        scanf("%d",&a[i]);
    int ans=0;
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            if (i!=j)
                ans+=(abs(a[i]-a[j])<=d);
    cout<<ans<<endl;                
    return 0;
}