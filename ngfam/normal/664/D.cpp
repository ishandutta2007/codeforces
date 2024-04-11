#include <bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 1; I <= (N); ++I)
#define REPP(I, A, B) for (int I = (A); I <= (B); ++I)
#define FOR(I, A, B) for(int I = (A); I >= (B) ; --I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define WI(X) printf("%d ", (X))
#define WII(X, Y) printf("%d %d\n", (X), (Y))
#define WIII(X, Y, Z) printf("%d %d %d\n", (X), (Y), (Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define PII pair<int,int>
#define VI vector<int>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >
#define F first
#define S second
#define str string
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
typedef long long LL;
using namespace std;
void home(){
    freopen("TEST.INP","r",stdin);
    freopen("TEST.OUT","w",stdout);
}
const int N=1e5+1, mod=1e9+7;
int n, m, dtplt; char color;
VPII adj[N], dsk[N]; VI tplt[N];
bool Free[N], change[N], recent[N];

struct answer{
    VI tv;
    int changes;
}dp[N][2];

void enter(){
    RII(n, m);
    REP(i, m){
        DRII(u, v); scanf(" %c", &color);
        if(color == 'B'){
            adj[u].PB(MP(v, 0));
            adj[v].PB(MP(u, 0));
        }
        else {
            adj[u].PB(MP(v, 1));
            adj[v].PB(MP(u, 1));
        }

    }
}

void Visit(int u){

    tplt[dtplt].PB(u);
    Free[u] = 1;

    REPP(i, 0, SZ(adj[u]) - 1){
        int v = adj[u][i].F;
        if(!Free[v]) Visit(v);
    }
}

void init(){
    REP(i, n)
      if(!Free[i]){
          dtplt++;
          Visit(i);
      }

    REP(i, n) dsk[i] = adj[i];
}

bool dfs(int u, bool is, int color){
    Free[u] = 1; recent[u] = is;

    REPP(i, 0, SZ(dsk[u]) - 1){
        int v = dsk[u][i].F, cl = dsk[u][i].S;
        if(!Free[v]){
            if(is) cl = 1 - cl;
            //cout << v << " " << (cl != color) << endl;
            if(!dfs(v, (cl != color) , color))return 0;
        }
        else {
            bool ischange = 1;
            if(is) cl = 1 - cl;
            if(cl == color) ischange = 0;

            if(ischange != recent[v]) return 0;
        }
    }

    return true;
}

bool cmp(answer u, answer v){
    return u.changes < v.changes;
}

answer sol(VI &a, int color){

    answer Count , ans ;
    Count . changes = ans.changes = 0;

    MS0(recent); MS0(Free);
    bool ok = dfs(a[0], 1, color);

    if(ok)
       REPP(i, 0, SZ(a) - 1){
           if(recent[a[i]])
              Count.changes ++, Count.tv.PB(a[i]);
       }
    else Count.changes = mod;

    MS0(recent); MS0(Free);
    ok = dfs(a[0], 0, color);

    if(ok)
       REPP(i, 0, SZ(a) - 1){
           if(recent[a[i]])
              ans.changes++, ans.tv.PB(a[i]);
       }
    else ans.changes = mod;

    return  min(Count, ans, cmp);
}
LL cl_0 = 0, cl_1 = 0;
int main(){
    //home();
    enter();
    init();
    REP(i, dtplt)
       dp[i][0] = sol(tplt[i], 0),
       dp[i][1] = sol(tplt[i], 1);

    REP(i, dtplt) cl_0 += dp[i][0].changes,
                  cl_1 += dp[i][1].changes;


    //cout << cl_1;
    if(min(cl_1, cl_0) >= mod){
            cout << -1;
            return 0;
        }
    if(cl_0 < cl_1){
        cout << cl_0 << endl;
        REP(i, dtplt)
            REPP(j, 0, SZ(dp[i][0].tv) - 1)
               WI(dp[i][0].tv[j]);
    }
    else{
        cout << cl_1 <<endl;
        REP(i, dtplt)
            REPP(j, 0, SZ(dp[i][1].tv) - 1)
               WI(dp[i][1].tv[j]);
    }
    return 0;
}