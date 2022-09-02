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

typedef long long ll;
typedef long double ld;

int n,h;
pair<int,int> a[110000];
int ans[110000];


int main(){
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

    scanf("%d %d",&n,&h);

    for (int i = 0; i < n; i++)
        scanf("%d",&a[i].first),a[i].second = i;

    sort(a,a+n);

    //for (int i = 0; i < n; i++)
    //    cerr << a[i].first <<" ";

    if (n == 2){
        printf("%d\n1 1\n",0);
        return 0;
    }

    int ans1 = max(a[n-1].first + a[n-2].first,a[n-1].first + a[0].first + h) - min(a[0].first + a[1].first + h, a[2].first + a[1].first); //!!!!
    int ans2 = a[n-1].first + a[n-2].first - a[0].first - a[1].first;

   // cerr << ans1 <<" "<<ans2 << endl;

    if (ans1 < ans2){
        printf("%d\n",ans1);
        for (int i = 0; i < n; i++)
            printf("%d ",1 + (i == a[0].second));
        printf("\n");
        return 0;
    }
    else {
        printf("%d\n",ans2);
        for (int i = 0; i < n; i++)
            printf("%d ",1);
        printf("\n");
        return 0;
    }
 

      
    return 0;
}