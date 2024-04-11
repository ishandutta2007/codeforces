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

const int MAXN = 110000;

vector<int> g[MAXN];

int comp[MAXN];
int compsize[MAXN];
int n;


bool checkluck(int x){
    if (x == 0)
        return false;
    for (;x;x/=10)
        if (x%10 != 4 && x%10 != 7)
            return false;
    return true;
}

int dfs(int v,int p,int c){
    comp[v] = c;
    int ans = 1;
    for (int i = 0; i < g[v].size(); i++)
        if (g[v][i] != p)
            ans += dfs(g[v][i],v,c);
    return ans;
}

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    scanf("%d",&n);
    for (int i = 0; i < n-1; i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        --a,--b;
        if (!checkluck(c)){
            g[a].pb(b);
            g[b].pb(a);
        }
    }

    int pt = 1;

    for (int i = 0; i < n;i++)
        if (comp[i] == 0){
           compsize[pt] = dfs(i,-1,pt);
           pt++; 
        }

    int64 ans = n*1LL*(n-1)*1LL*(n-2);

    for (int i = 0; i < n; i++){
        ans -= 2LL*(compsize[comp[i]]-1)*1LL*(n-2);
        ans += (compsize[comp[i]]-1)*1LL*(compsize[comp[i]]-2);
    }

    cout << ans << endl;        

    return 0;
}