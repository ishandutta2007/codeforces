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

#define TASKNAME "D"

typedef long long ll;
typedef long double ld;

const int MAXN = 1110000;

int n,m;

vector<int> g[MAXN];

int used[MAXN];
vector<int> ans;

void dfs(int v){
//  eprintf("%d\n",v);
    if (used[v] == 1){
        printf("-1\n");
        exit(0);
    }
    if (used[v] == 2) {
//      eprintf("out %d\n",v);
        return;
    }
    used[v] = 1;
    for (int i = 0; i < (int)g[v].size(); i++)
        dfs(g[v][i]);
    used[v] = 2;
    if (v < m) ans.pb(v+1);
//  eprintf("out %d\n",v);
}


int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif

    scanf("%d %d",&n,&m);

    int cnt = m;

    for (int it = 0; it < n; it++){
        vector<pair<int,int> > v(m);
        for (int j = 0; j < m; j++)
            scanf("%d",&v[j].first), v[j].second = j;
        sort(v.begin(),v.end());
        int last = -1;    
        for (int i = 0; i < m;){
            int j = i;
            while (j < m && v[j].first == v[i].first)
                j++;
            if (v[i].first == -1){ i = j; continue;};
            for (; i < j; i++){                       
//              eprintf("%d -> %d -> %d\n", last, v[i].second, cnt);
                if (last != -1) g[last].pb(v[i].second);
                g[v[i].second].pb(cnt);
            }
            last = cnt++;
        }
    }

    for (int i = 0; i < cnt; i++)
        dfs(i);

    reverse(ans.begin(),ans.end());
    for (int i = 0; i < m; i++)
        printf("%d%c",ans[i]," \n"[i==m-1]);  

    return 0;
}