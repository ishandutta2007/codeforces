#include <bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
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
typedef long long LL;
using namespace std;
void home(){
    freopen("TEST.INP","r",stdin);
    freopen("TEST.OUT","w",stdout);
}
const int maxN=1e2+1;
const int mod=1e9+7;
int n,m,d,Array[maxN][maxN], dem [maxN];
VI A;
int main(){
    //home();
    RIII(n, m, d);
    REP(i, n)
       REP(j, m) RI(Array[i][j]);
    REP(i, n)
       REP(j, m) A.PB(Array[i][j]);

    sort(ALL(A));

    n = SZ(A);

    REP(i, n - 1)
       if ((A[i + 1] - A[i]) % d != 0){ cout << -1 ; exit(0) ;}

    REP(i, n) dem[i] = (A[i] - A[0]) / d;
    m = (A[n - 1] - A[0]) / d;
    //cout << A[n - 1];
    int ans = mod;
    //cout << ans;
    REP(j, m + 1){
        int res = 0;
        REP(i, n) res += abs(j - dem[i]);
        ans = min(ans, res);
        //if(ans == 110) cout << j;
    }
    cout <<ans;
    return 0;
}