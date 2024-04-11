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

int sz[1510];

vector<int> g[1510];


int x[1510];
int y[1510];
int ver[1510];
int n;

int initsz(int v,int p){
    sz[v] = 1;
    for (int i = 0; i < (int)g[v].size(); i++){
        if (g[v][i] == p)
            continue;
        sz[v] += initsz(g[v][i],v);
    }                           
    return sz[v];
}

bool cmp(int a,int b){
    return x[a] * 1LL * y[b] - x[b] * 1LL * y[a] > 0;
}

bool cmpxy(int a,int b){
    if (y[a] != y[b])
        return y[a] < y[b];
    return x[a] < x[b];
}

int ord[1510];


void solve(int v,int p,int l,int r){
    //cerr << v <<" "<< p <<" "<<l <<" "<<r << endl;
    iter_swap(ord+l,min_element(ord+l,ord+r,cmpxy));
    for (int i = l+1; i < r; i++)
       x[ord[i]] -= x[ord[l]], y[ord[i]] -= y[ord[l]];
    x[ord[l]] = y[ord[l]] = 0;
    sort(ord+l+1,ord+r,cmp);
    ver[ord[l]] = v;
    int ptr = l+1;
    for (int i = 0; i <(int)g[v].size(); i++){
        if (g[v][i] == p)
            continue;
        solve(g[v][i],v,ptr,ptr+sz[g[v][i]]);
        ptr += sz[g[v][i]];
    }
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
        g[a].pb(b);
        g[b].pb(a);
    }
    for (int i = 0; i < n; i++)
        scanf("%d %d",&x[i],&y[i]),ord[i] = i;
    
    initsz(0,-1);
    solve(0,-1,0,n);

    for (int i = 0; i < n; i++)
        printf("%d ",ver[i]+1);

  return 0;
}