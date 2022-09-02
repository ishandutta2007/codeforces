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

const int MAXM=110000;

int a[MAXM],b[MAXM],c[MAXM];
int r;

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    for (int i=0;i<m;i++)
        scanf("%d %d %d",&a[i],&b[i],&c[i]);
    int64 sum=0;
    for (int i=0;i<k;i++){
        scanf("%d",&r);
        for (int j=0;j<m;j++)
            if (r>=a[j] && r<=b[j])
                sum+=c[j]+(r-a[j]);
    }
    cout<<sum<<endl;    
    return 0;
}