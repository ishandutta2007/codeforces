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

#define TASKNAME "E"

#ifdef LOCAL
static struct __timestamper {
    ~__timestamper(){
        TIMESTAMP(end);
    }
} __TIMESTAMPER;
#endif

typedef long long ll;
typedef long double ld;

const int MAXN = 10000;

vector<int> g[MAXN];
vector<int> len[MAXN];

int lf[MAXN];
int rg[MAXN];

int lf_bak[MAXN];
int rg_bak[MAXN];


ll dst[MAXN];
int pl[MAXN];

bool canDraw[MAXN];

set< pair<ll,int> > s;


void relax(int v, ll cost, int p){
    if (dst[v] > cost){
        s.erase(mp(dst[v], v));
        dst[v] = cost;
        pl[v] = p;
        canDraw[v] = (p == 2);
        s.insert(mp(dst[v], v));
    }
    else if (dst[v] == cost){
        if (pl[v] != p)
            canDraw[v] = true;
    }
}

int s1,s2,f;


bool trySolve(bool wantWin){
    memset(dst, 0x3f, sizeof(dst));
    s.clear();

    relax(s1, 0, 0);
    relax(s2, 0, 1);

    while (!s.empty()){
        int v = s.begin()->second;
        s.erase(s.begin());
        if (v == f){
            if (canDraw[v])
               return !wantWin;
            return pl[v] == 0;
        }
        if (canDraw[v])
            pl[v] = 2;
        for (int i = 0; i < (int)g[v].size(); i++){
            int nv = g[v][i];
            ll nlen = len[v][i];
            if (nlen < 0){
                if (pl[v] == 0 || (pl[v] == 2 && !wantWin)){
                    nlen = rg[-nlen - 1] = lf[-nlen - 1];
                } else {
                    nlen = lf[-nlen - 1] = rg[-nlen - 1];
                }
            }
            relax(nv, nlen + dst[v], pl[v]);
        }
    }
    return !wantWin;
}


int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif

    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    scanf("%d %d %d",&s1,&s2,&f);
    --s1,--s2,--f;

    for (int i = 0; i < m; i++){
        int a,b, l;
        scanf("%d %d %d",&a,&b,&l);
        --a,--b;
        g[a].pb(b); len[a].pb(l);
//      g[b].pb(a); len[b].pb(l);
    }

    for (int i = 0; i < k; i++){
        int a,b;
        scanf("%d %d %d %d",&a,&b,&lf[i],&rg[i]);
        --a,--b;
        g[a].pb(b); len[a].pb(-i-1);
//      g[b].pb(a); len[b].pb(-i-1);
    }

    memcpy(lf_bak, lf, sizeof(lf));
    memcpy(rg_bak, rg, sizeof(rg));

    if (trySolve(1)){
        printf("WIN\n");
        for (int i = 0; i < k; i++)
            printf("%d%c", lf[i], " \n"[i==k-1]);
        return 0;
    }

    memcpy(lf, lf_bak, sizeof(lf));
    memcpy(rg, rg_bak, sizeof(rg));

    if (trySolve(0)){
        printf("DRAW\n");
        for (int i = 0; i < k; i++)
            printf("%d%c", lf[i], " \n"[i==k-1]);
        return 0;
    }

    printf("LOSE\n");
    return 0;
}