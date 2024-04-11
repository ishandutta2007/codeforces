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

int a[110000];
int n,k;

bool check(ld val){
    ld more,need;
    more = need = 0;
    for (int i=0;i<n;i++){
        if (a[i] > val)
            more += a[i]-val;
        else
            need += (val-a[i])/(1-k/100.0);
    }
    return need <= more;        
}

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    scanf("%d %d",&n,&k);
    for (int i=0;i<n;i++)
        scanf("%d",&a[i]);
    
    sort(a,a+n);

    ld l=a[0];
    ld r=a[n-1];
    
    for (int i=0;i<200;i++){
        ld m=(l+r)/2;
        if (check(m))
            l=m;
        else
            r=m;
    }
    
    cout.precision(15);
    
    cout<<fixed << l <<endl;
    
    return 0;
}