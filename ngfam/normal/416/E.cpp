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
#define LEN(X) (int)(X).length()
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
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    freopen("TEST.INP","r",stdin);
    freopen("TEST.OUT","w",stdout);
}
const int N =5e2 + 1, mod=1e9+7;
int n, c[N][N], d[N][N], m, cnt[N][N], result[N][N];

void enter(){
    memset(d, 63, sizeof(d));
    memset(c, 63, sizeof(c));
    //cout << d[0][0] << endl;
    RII(n, m);
    REP(i, m){
         DRIII(x, y, z);
         c[x][y] = z;
         c[y][x] = z;
         d[x][y] = z;
         d[y][x] = z;
    }
    REP(i, n)  d[i][i] = 0;
}

void solve(){
    REP(k, n)
        REP(i, n)
            REP(j, n)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

    //cout << d[1][4];

    REP(i, n)
        REP(j, n)
            REP(u, n)
                if(c[u][j] < mod)
                    if(d[i][u] + c[u][j] == d[i][j])
                        cnt[i][j]++;

    REP(i, n)
        REPP(j, i + 1, n)
            REP(u, n)
                if(d[i][u] + d[u][j] == d[i][j])
                    result[i][j] += cnt[i][u];
   REP(i, n)
       REPP(j, i + 1, n)
           cout << result[i][j] << " ";
}

int main(){
    //home();
    enter();
    solve();
    return 0;
}