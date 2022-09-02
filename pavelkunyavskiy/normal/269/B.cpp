#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <functional>
#include <bitset>
#define mp make_pair
#define pb push_back

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

#define TASKNAME "B"

typedef long long ll;
typedef long double ld;

int dp[5100];


int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif

    int n,m;
    scanf("%d %d",&n,&m);

    for (int i = 0; i < n; i++){
        int a;
        scanf("%d %*f",&a);

        for (int j = m; j >= 1; j--){ 
            if (j != a)
                dp[j] = dp[j] + 1;
            else
                dp[j] = *min_element(dp+1,dp+j+1);
        }           
    }

    cout << *min_element(dp+1,dp+m+1) << endl;

      
  return 0;
}