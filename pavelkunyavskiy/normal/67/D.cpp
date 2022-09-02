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

const int MAXN=1100000;

int a[MAXN];
int b[MAXN];
int c[MAXN];

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        int tmp;
        scanf("%d",&tmp);
        a[tmp]=n-i-1;
    }
    for (int i=0;i<n;i++){
        scanf("%d",&b[i]);
        b[i]=a[b[i]];
    }
    
    for (int i=0;i<=n;i++)
        c[i]=n+100;
    for (int i=0;i<n;i++)
        *lower_bound(c,c+n,b[i])=b[i];
    int ans=0;
    for (;c[ans]<n;++ans);
    cout<<ans<<endl;
    return 0;
}