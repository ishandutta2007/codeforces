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

#define TASKNAME "C"

#ifdef LOCAL
static struct __timestamper {
    string what;
    __timestamper(const char* what) : what(what){};
    __timestamper(const string& what) : what(what){};
    ~__timestamper(){
        TIMESTAMPf("%s", what.data());
    }
} __TIMESTAMPER("end");
#else 
struct __timestamper {};
#endif

typedef long long ll;
typedef long double ld;

const int inf = 1e9;


class Tree {
    vector<int> bit;
    void update(int x, int y){
        for (; x < (int)bit.size(); x = (x | (x+1)))
            bit[x] += y;
    }

public:
    Tree(int n = 0): bit(n){}

    void update(int l, int r, int y){
//      eprintf("update [%d..%d] %d\n", l, r, y);
        update(l, y);
        update(r + 1, -y);
    }

    int get(int x){
//      eprintf("get [%d]\n", x);
        int sum = 0;
        for (; x != -1; x = (x & (x + 1)) - 1)
            sum += bit[x];
        return sum;
    }
};

vector<int> ord[2];
Tree tree[2];

const int MAXN = 200000;

vector<int> g[MAXN];
int l[2][MAXN];
int r[2][MAXN];
int pos[MAXN];
int h[MAXN];


void dfs(int v,int p, int h){
    ::h[v] = h;
    l[h][v] = r[h][v] = pos[v] = ord[h].size();
    l[h ^ 1][v] = inf; r[h ^ 1][v] = -inf;
    ord[h].pb(v);

    for (int i = 0; i < (int)g[v].size(); i++)
        if (g[v][i] != p){
            dfs(g[v][i], v, h ^ 1);
            for (int j = 0; j < 2; j++) {
                l[j][v] = min(l[j][g[v][i]], l[j][v]);
                r[j][v] = max(r[j][g[v][i]], r[j][v]);
            }
        }
}






int main(){
  #ifdef LOCAL
    assert(freopen(TASKNAME".in","r",stdin));
    assert(freopen(TASKNAME".out","w",stdout));
  #endif
    int n,q;
    while (scanf("%d%d", &n,&q) == 2) {
        for (int i = 0; i < n; i++){
            g[i].clear();
        }
        vector<int> init(n);
        for (int i = 0; i < n; i++)
            scanf("%d", &init[i]);
        for (int i = 0; i < n-1; i++){
            int a,b;
            scanf("%d %d",&a, &b);
            --a, --b;
            g[a].pb(b);
            g[b].pb(a);
        }

        dfs(0, -1, 0);

        tree[0] = Tree(ord[0].size());
        tree[1] = Tree(ord[1].size());

        for (int i = 0; i < n; i++){
            tree[h[i]].update(pos[i], pos[i], init[i]);
            if (r[0][i] < 0) r[0][i] = l[0][i] = inf;
            if (r[1][i] < 0) r[1][i] = l[1][i] = inf;
        }


        for (int i = 0; i < q; i++){
            int ty;
            scanf("%d", &ty);
            if (ty == 1) {
               int x, val;
               scanf("%d %d",&x, &val);
               --x;
               tree[h[x]].update(l[h[x]][x], r[h[x]][x], val);
               tree[h[x]^1].update(l[h[x]^1][x], r[h[x]^1][x], -val);
            } else {
                int x;
                scanf("%d", &x);
                --x;
                printf("%d\n", tree[h[x]].get(pos[x]));
            }
        }



    }

      
  return 0;
}