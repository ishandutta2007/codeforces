#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <iterator>
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

typedef long long int64;
typedef long double ld;

vector<int> g[100000];
int p[100000];
int n;
      
void dfs(int v,int p=-1){
    ::p[v]=p;
    int sz=g[v].size();
    for (int i=0;i<sz;i++)
        if (g[v][i]!=p)
            dfs(g[v][i],v);
}
    
int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int r1,r2;
    scanf("%d %d %d",&n,&r1,&r2);
    --r1,--r2;
    for (int i=0;i<n;i++){
        if (i==r1)
            continue;
        int a;
        scanf("%d",&a);
        --a;
        g[a].pb(i);
        g[i].pb(a);
    }
    dfs(r2);
    for (int i=0;i<n;i++)
        if (i!=r2)
            printf("%d ",p[i]+1);
    printf("\n");
    return 0;
}