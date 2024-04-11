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
#define forn(i,n) for(int i=0;i<(n);++i)
#define ford(i,n) for(int i=(n)-1;i>=0;--i)

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

typedef long long int64;
typedef long long ll;
typedef double ld;

int x[5100],y[5100],z[5100];

ld dst[5100];

ld dest(int a,int b){
    int dx=x[a]-x[b];
    int dy=y[a]-y[b];
    int dz=z[a]-z[b];
    return sqrt(dx*dx+dy*dy+dz*dz); 
}



int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%d %d %d",&x[i],&y[i],&z[i]);
    for (int i=0;i<n;i++)
        dst[i]=dest(0,i);
    ld ans=1e+100;
    for (int i=1;i<n;i++)
        for (int j=i+1;j<n;j++){
                ld tmp=dst[i]+dst[j]+dest(i,j);
                if (ans>tmp)
                    ans=tmp;
            }
    ans/=2;
    cout.precision(15);
    cout<<ans<<endl;
    return 0;
}