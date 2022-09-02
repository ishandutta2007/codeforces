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

const int MAXN = 3100;

int n;
vector<int> g[MAXN];
vector<int> l[MAXN];
vector<int> dp[MAXN][3][2];


int calc(int v,int have,int need,int p,int son){
    if (have < 0)
        return 1<<29;
    if (son == -1){
        if (!have && !need)
            return 1<<29;
        return 0;
    }
    int& ans = dp[v][have][need][son];
    if (ans != -1)
        return ans;
    ans = 1<<29;
    if (g[v][son] == p)
        return ans = calc(v,have,need,p,son-1);
    int to = g[v][son];
    ans = calc(v,have-1,1,p,son);

    ans = min(ans, calc(v,have-1,1,p,son-1) + calc(to,1,0,v,g[to].size()-1) + (l[v][son] == 1));
    ans = min(ans, calc(v,have-2,1,p,son-1) + calc(to,2,0,v,g[to].size()-1) + (l[v][son] == 1));

    ans = min(ans, calc(v,have,need,p,son-1) + calc(to,0,1,v,g[to].size()-1) + (l[v][son] == 0));
    if (have) ans = min(ans, calc(v,have-1,need,p,son-1) + calc(to,1,1,v,g[to].size()-1) + (l[v][son] == 0));
    if (have >= 2) ans = min(ans, calc(v,have-2,need,p,son-1) + calc(to,2,1,v,g[to].size()-1) + (l[v][son] == 0));


    return ans;
}


int main(){
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

    scanf("%d",&n);

    for (int i = 0; i < n-1; i++){
        int a,b;
        scanf("%d %d",&a,&b);
        --a,--b;
        g[a].pb(b),l[a].pb(1);
        g[b].pb(a),l[b].pb(0);
        for (int k = 0; k < 3; k++)
            for (int l = 0; l < 2; l++){
                dp[a][k][l].pb(-1);
                dp[b][k][l].pb(-1);
            }
    }

    cout << calc(0,2,0,-1,g[0].size()-1) << endl;
      
    return 0;
}