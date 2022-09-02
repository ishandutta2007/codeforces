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


const int MAXN = 110000;
vector<int> g[MAXN];
vector<int> gt[MAXN];

bool used1[MAXN];
bool used2[MAXN];
int n,m;
int f[MAXN];

void dfs1(int v){
    if (used1[v])
        return;
    used1[v] = true;
    for (int i = 0; i < (int)g[v].size(); i++)
        dfs1(g[v][i]);
}

void dfs2(int v){
    if (used2[v])
        return;
    used2[v] = true;
    if (f[v] == 1)
        return;
    for (int i = 0; i < (int)gt[v].size(); i++)
        dfs2(gt[v][i]);
}

int main(){
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    scanf("%d %d",&n,&m);
    for (int i = 0; i < n; i++)
        scanf("%d",&f[i]);
    for (int i = 0; i < m; i++){
        int a,b;
        scanf("%d %d",&a,&b);
        --a,--b;
        g[a].pb(b);
        gt[b].pb(a);
    }

    for (int i = 0; i < n; i++)
        if (f[i] == 1)
            dfs1(i);

    for (int i = 0; i < n; i++)
        if (f[i] == 2)
            dfs2(i);

    for (int i = 0; i < n; i++)
        if (used1[i] && used2[i])
            printf("1\n");
        else
            printf("0\n"); 

  return 0;
}