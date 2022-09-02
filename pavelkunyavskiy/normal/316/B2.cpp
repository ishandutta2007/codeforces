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
#define TIMESTAMPf(x,...) eprintf("[" x "] Time : %.3lf s.\n", __VA_ARGS__, clock()*1.0/CLOCKS_PER_SEC)

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

#define TASKNAME "B"

typedef long long ll;
typedef long double ld;

int n,x;
int next[11000];
bool first[11000];

vector<int> a;

int dfs(int v){
    if (v == -1) return 0;
    if (v == x) return -1000000;
    return 1 + dfs(next[v]);
}

bool can[11000];

int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif

    scanf("%d %d",&n,&x);
    --x;
    memset(first,1,sizeof(first));
    for (int i = 0; i < n; i++)
        scanf("%d",&next[i]), --next[i], first[next[i]] = false;

    int ans = dfs(next[x])+1;
    
    for (int i = 0; i < n; i++)
        if (first[i]){
            int temp = dfs(i);
            if (temp > 0)
                a.pb(temp);
        }

    can[0] = 1;

    for (int i = 0; i < (int)a.size(); i++){
        for (int j = n; j >= a[i]; j--)
            can[j] |= can[j-a[i]];
    }

    for (int i = 0; i <= n; i++)
        if (can[i])
            printf("%d\n",ans+i);

    

      
    TIMESTAMP(end);
    return 0;
}