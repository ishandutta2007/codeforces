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
int k;


      
    
int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=0;i<m;i++)
        a[i]=1<<30;
    for (int i=0;i<n;i++){
        int r,c;
        cin>>r>>c;
        --r;
        a[r]=min(a[r],c);
    }
    int64 sum=0;
    for (int i=0;i<m;i++)
        sum+=a[i];
    if (sum>k)
        sum=k;
    cout<<sum<<endl;
    return 0;
}