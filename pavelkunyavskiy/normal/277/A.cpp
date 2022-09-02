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

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

#define TASKNAME "A"

typedef long long ll;
typedef long double ld;

const int MAXN = 110;

vector<int> g[MAXN*2];

bool used[MAXN*2];

void dfs(int v){
    if (used[v]) return;
    used[v] = true;
    for (int i = 0; i < (int)g[v].size(); i++)
        dfs(g[v][i]);

}



int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif
    int n,m;

    scanf("%d %d",&n,&m);

    bool any = false;

    for (int i = 0; i < n; i++){
        int k;
        scanf("%d",&k);
        any |= (k != 0);
        for (int j = 0; j < k; j++){
            int b;
            scanf("%d",&b);
            b += n-1;
            g[i].pb(b);
            g[b].pb(i);
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
        if (!used[i])
            ans++, dfs(i);

    ans = max(0, ans-any);

    printf("%d\n",ans);

      
  return 0;
}