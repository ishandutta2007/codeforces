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
typedef long double ld;

int a[1000];

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int n,l;
    scanf("%d %d",&n,&l);
    for (int i=0;i<n;i++)
        scanf("%d",&a[i]);
    int best=0;
    for (int i=max(l,1);i<=200;i++){
        int tmp=0;
        for (int j=0;j<n;j++)
            tmp+=a[j]/i;
        best=max(best,i*tmp);
    }
    cout<<best<<endl;
    return 0;
}