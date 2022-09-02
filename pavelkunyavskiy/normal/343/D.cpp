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

#define TASKNAME "D"

typedef long long ll;
typedef long double ld;


const int MAXN = 510000;
const int MAXLST = 1<<19;
const int MAXSZ = 2*MAXLST + 100;

int tree[MAXSZ];
int upd[MAXSZ];
int lst = 0;


vector<int> g[MAXN];
int tin[MAXN];
int tout[MAXN];

void dfs(int v,int p){
    static int timer = 0;
//  eprintf ("%d ", v);
    tin[v] = timer++;
    for (int i = 0; i < (int)g[v].size(); i++)
        if (g[v][i] != p)
            dfs(g[v][i],v);
    tout[v] = timer - 1;
}

void update(int v,int l,int r,int L,int R, int val){
//  eprintf("%d [%d..%d] [%d..%d] to %d\n", v, l, r, L, R, val);
    if (r < L || R < l) return;
    if (L <= l && r <= R){
        upd[v] = val;
        return;
    }
    if (upd[v] != -1)
        upd[2*v] = upd[2*v+1] = upd[v];
    upd[v] = -1;
    update(2*v, l, (l+r)/2, L, R, val);
    update(2*v+1, (l+r)/2+1, r, L, R, val);
}

void update(int pos,int val){
    pos = pos + lst;
    tree[pos] = val;
    pos /= 2;
    while (pos){ 
        tree[pos] = max(tree[2*pos], tree[2*pos+1]);
        pos /= 2;
    }
}

int get(int v,int l,int r,int L,int R){
    if (r < L || R < l) return -1;
    if (L <= l && r <= R){
        return tree[v];
    }
    return max(
               get(2*v, l, (l+r)/2, L, R),
               get(2*v+1, (l+r)/2+1, r, L, R)
              );
}

int get(int pos){
    pos = pos + lst;
    int ans = upd[pos];
    pos /= 2;
    while (pos){ 
        if (upd[pos] != -1)
           ans = upd[pos];
        pos /= 2;
    }
    return ans;
}



int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif

    int n;
    scanf("%d",&n);
    for (int i = 0; i < n-1; i++){
        int a,b;
        scanf("%d %d",&a,&b);
        --a,--b;
        g[a].pb(b);
        g[b].pb(a);
    }

    dfs(0, -1);
//    eprintf("\n");

    lst = 2;
    while (lst < n) lst *= 2;

    for (int i = 1; i < 2*lst; i++){
        tree[i] = 1;
        upd[i] = 0;
    }

    int q;
    scanf("%d",&q);
    for (int it = 2; it < q+2; it++){
        int ty,v;
        scanf("%d %d",&ty,&v);
        --v;
        if (ty == 1)
            update(1, 0, lst-1, tin[v], tout[v], it);
        else if (ty == 2)
            update(tin[v], it);
        else {
            int lastFill = get(tin[v]);
            int lastUnFill = get(1, 0, lst-1, tin[v], tout[v]);
//          eprintf("Fill = %d, Unfill = %d\n", lastFill, lastUnFill);
            if (lastFill < lastUnFill)
                printf("0\n");
            else
                printf("1\n");
        }
    }
    TIMESTAMP(end);
    return 0;
}