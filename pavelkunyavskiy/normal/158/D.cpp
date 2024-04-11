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

int a[21000];
int n;

int main(){
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
        scanf("%d",&a[i]);

    int ans = -(1<<30);

    for (int i = 1; i <= n; i++){
        if (n % i || n/i < 3)
            continue;
        for (int j = 0; j < i; j++){
            int cur = 0;
            for (int k = 0; k*i+j <n; k++)
                cur += a[k*i+j];
            ans = max(ans,cur);
        }
    }

    cout << ans << endl;
    return 0;
}