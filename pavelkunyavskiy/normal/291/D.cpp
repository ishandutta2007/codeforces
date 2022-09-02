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

#define TASKNAME "D"

typedef long long ll;
typedef long double ld;

int a[110000];
int b[110000];

vector<int> ans[110000];
int n,k;

           
int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif
    scanf("%d %d",&n,&k);

    for (int i = 0; i < n-1; i++)
        a[i] = 1;

    for (int i = 0; i < k; i++){
        ans[i].resize(n);
        for (int j = 0; j < n; j++){
            ans[i][j] = lower_bound(a,a+n,(n-j-1) - a[j],greater<int>()) - a;
            printf("%d%c",ans[i][j]+1," \n"[j==n-1]);
        }
        for (int j = 0; j < n; j++)
            b[j] = a[j] + a[ans[i][j]];
        for (int j = 0; j < n; j++)
            a[j] = b[j];
    }
        

      
  TIMESTAMP(end);
  return 0;
}