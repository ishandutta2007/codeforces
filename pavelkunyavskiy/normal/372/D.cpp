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

#if ( ( _WIN32 || __WIN32__ ) && __cplusplus < 201103L)
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

#define TASKNAME "D"

#ifdef LOCAL
static struct __timestamper {
    string what;
    __timestamper(const char* what) : what(what){};
    __timestamper(const string& what) : what(what){};
    ~__timestamper(){
        TIMESTAMPf("%s", what.data());
    }
} __TIMESTAMPER("end");
#endif

typedef long long ll;
typedef long double ld;

const int MAXN = 110000;
const int MAXLOG = 18;

int h[MAXN];
int up[MAXLOG][MAXN];
int tin[MAXN];
int timer;

struct TimeComparer {
    bool operator()(int a,int b){
        return tin[a] < tin[b];
    }
};

typedef set<int, TimeComparer> Vset;

 vector<int> g[MAXN];

void dfs(int v,int p,int h){
    tin[v] = timer++;
    ::h[v] = h;
    up[0][v] = p;
    for (int i = 0; i < (int)g[v].size(); i++)
        if (g[v][i] != p) {
//          eprintf("%d -> %d\n", v+1, g[v][i]+1);
            dfs(g[v][i], v, h+1);
        }
}

void next(const Vset& a, Vset::iterator& it){
    it++;
    if (it == a.end())
        it = a.begin();
}

void prev(const Vset& a, Vset::iterator& it){
    if (it == a.begin())
        it = a.end();
    it--;
}


int n;
void initlca(){
    for (int i = 1; i < MAXLOG; i++)
        for (int j = 0; j < n; j++)
            up[i][j] = up[i-1][up[i-1][j]];
}

int getup(int v,int h){
    assert(h >= 0);
    for (int i = 0; i < MAXLOG; i++)
        if (h & (1<<i))
            v = up[i][v];
    return v;
}

int getlca(int u,int v){
    if (h[u] < h[v]) swap(u, v);
    u = getup(u, h[u] - h[v]);
    if (u == v) return v;
    for (int i = MAXLOG - 1; i >= 0; i--)
        if (up[i][v] != up[i][u])
            v = up[i][v], u = up[i][u];
    assert(up[0][v] == up[0][u]);
    return up[0][v];
}

int getDst(int u,int v){
    if (u == n || v == n)
        return 1e8;
    int c = getlca(u, v);
    return h[u] + h[v] - 2*h[c];
}


Vset vs;
ll cursum;


void insert(int x){
//  eprintf("insert %d\n", x);
    Vset::iterator iter = vs.insert(x).first;
    next(vs,iter);
    int u = *iter;
    prev(vs,iter);  prev(vs,iter);
    int v = *iter;
    cursum -= getDst(u, v);
    cursum += getDst(u, x);
    cursum += getDst(x, v);
}

void erase(int x){
//  eprintf("erase %d\n", x);
    Vset::iterator iter = vs.find(x);
    assert(iter != vs.end());
    next(vs,iter);
    int u = *iter;
    prev(vs,iter);  prev(vs,iter);
    int v = *iter;
    cursum += getDst(u, v);
    cursum -= getDst(u, x);
    cursum -= getDst(x, v);
    vs.erase(x);
}



int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif
    int k;
    scanf("%d %d",&n,&k);
    k = 2*k-2;

    for (int i = 0; i < n-1; i++){
        int a,b;
        scanf("%d %d",&a, &b);
        --a,--b;
        g[a].pb(b);
        g[b].pb(a);
    }

    dfs(0, 0, 0);
    tin[n] = timer++;
    initlca();

    int ptr = 0;
    cursum = 0;
    int ans = 0;

    for (int i = 0; i < n; i++){
        while (cursum <= k) {
            insert(ptr++);
//          eprintf("[%d..%d] %I64d\n", i+1, ptr, cursum);
        } 
//          eprintf("cur = %d\n", ptr - i - 1);
        ans = max(ans, ptr - i - 1);
        erase(i);
//      eprintf("[%d..%d] %I64d\n", i+2, ptr, cursum);
    }
    printf("%d\n", ans);      
    return 0;
}