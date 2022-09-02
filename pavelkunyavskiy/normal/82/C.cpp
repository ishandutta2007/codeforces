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


const int MAXN=5100;

int p[MAXN];
int cur[MAXN];
int w[MAXN];
int pos[MAXN];
int ans[MAXN];
int por[MAXN];
int prior[MAXN];



vector<int> g[MAXN];
vector<int> W[MAXN];


void dfs(int v,int p,int w){
    ::p[v]=p;::w[v]=w;
    for (int i=0;i<g[v].size();i++)
        if (g[v][i] != p)
            dfs(g[v][i],v,W[v][i]); 
}

int ITER=0;
int n;

void iterate(){
    for (int i=0;i<n;i++){
        if (pos[i]==0)
            ans[i]=ITER;
        cur[i]=w[i];
    }
    for (int i=0;i<n;i++){
        int v = por[i];
        if (pos[v] != -1){
            if (pos[v]==0 || cur[pos[v]] > 0){
                --cur[pos[v]];
                pos[v] = p[pos[v]];
            }
        }
    }
    ++ITER; 
}

bool priorcmp(int a,int b){
    return prior[a] < prior[b];
}

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d",&prior[i]);
        por[i]=i;
        pos[i]=i;
    }
    for (int i=0;i<n-1;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        --a,--b;
        g[a].pb(b);
        g[b].pb(a);
        W[a].pb(c);
        W[b].pb(c);
    }
    sort(por,por+n,priorcmp);
    dfs(0,-1,1<<29);
    for (int i=0;i<n;i++)
        iterate();
    for (int i=0;i<n;i++)
        printf("%d ",ans[i]);
    printf("\n");
    return 0;
}