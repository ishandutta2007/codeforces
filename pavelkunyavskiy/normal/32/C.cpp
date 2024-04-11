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

int64 n,m,s;

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    cin>>n>>m>>s;
    int64 n1=n%s;
    if (n1==0)
        n1+=s;
    int64 m1=m%s;
    if (m1==0)
        m1+=s;
    int64 ans=n1*m1;
    int64 n2=n/s;
    if (n2*s!=n)
        ++n2;
    int64 m2=m/s;
    if (m2*s!=m)
        ++m2;
    cout<<ans*n2*m2<<endl;
    return 0;
}