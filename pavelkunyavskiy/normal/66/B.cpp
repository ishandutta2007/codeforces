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

int n;
int a[1100];

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%d",&a[i]);
    int best = 1;
    for (int i=0;i<n;i++){
        int ans = 1;
        for (int j=i-1;j>=0 && a[j]<=a[j+1];--j)
            ans++;
        for (int j=i+1;j<n && a[j]<=a[j-1];++j)
            ans++;
        best = max(best,ans);           
    }
    cout<<best<<endl;
    return 0;
}