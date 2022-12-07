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
	cin.tie(0);
    freopen("TEST.INP","r",stdin);
    freopen("TEST.OUT","w",stdout);
}
const int N=1e6+1, mod=1e9+7;

int n, m, sl1, sl2;
char n1[30], n2[30];
LL result; bool ok;

int main(){
   // home();
    cin >> n >> m;
    itoa(n - 1, n1, 7);
    sl1 = strlen(n1);
    itoa(m - 1, n2, 7);
    sl2 = strlen(n2);

    //cout << n2;

    if(sl1 + sl2 > 7) {
        cout << 0;
        return 0;
    }

    REPP(i, 0, n - 1)
        REPP(j, 0, m - 1){
             itoa(i, n1, 7);
             itoa(j, n2, 7);

             str  a = str(n1), b = str(n2);

             while(SZ(a) < sl1) a = "0" + a;
             while(SZ(b) < sl2) b = "0" + b;
             bool ok = 1;

             REPP(i, 0, SZ(a) - 2)
                 REPP(j, i + 1, SZ(a) - 1)
                      if(a[i] == a[j]) ok = false;

             REPP(i, 0, SZ(b) - 2)
                 REPP(j, i + 1, SZ(b) - 1)
                 if(b[i] == b[j]) ok = false;

             REPP(k, 0, SZ(a) - 1)
                 REPP(h, 0, SZ(b) - 1)
                     if(a[k] == b[h]) ok = 0;
            // if(ok) cout << a << " " << b << endl;
             result += ok;
        }
    cout << result;
    return 0;
}