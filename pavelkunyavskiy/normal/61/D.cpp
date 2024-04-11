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

typedef long long int64;
typedef long double ld;

vector<int> g[110000];
vector<int> c[110000];

int64 dfs(int v,int p){
    int64 ans=0;
    for (int i=0;i<g[v].size();i++)
        if (g[v][i] != p)
            ans=max(ans,dfs(g[v][i],v)+c[v][i]);
    return ans;
}



int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int n;
    scanf("%d",&n);
    int64 ans=0;
    for (int i=0;i<n-1;i++){    
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        --a,--b;
        g[a].pb(b);
        g[b].pb(a);
        ::c[a].pb(c);   
        ::c[b].pb(c);
        ans+=2*c;
    }
    ans-=dfs(0,-1);
    cout<<ans<<endl;
    return 0;
}