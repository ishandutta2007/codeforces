//#include <iostream>
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
#include <sstream>
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

#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("["#x"] Time : %.3lf s.\n", clock()*1.0/CLOCKS_PER_SEC)

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

#define TASKNAME "B"

typedef long long ll;
typedef long double ld;


map<int,int> a;

int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif

    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);

    for (int i = 0; i < n; i++){
        int x;
        scanf("%d",&x);
        a[x]++;
    }

    for (int i = 0; i < m; i++){
        int x;
        scanf("%d",&x);
        a[x]--;
    }

    int sum = 0;

    for (map<int,int>::reverse_iterator iter = a.rbegin(); iter != a.rend(); ++iter){
        sum += iter->second;
        if (sum > 0){
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");      
    TIMESTAMP(end);
    return 0;
}