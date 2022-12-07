#include <bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 1; I <= (N); ++I)
#define REPP(I, A, B) for (int I = (A); I <= (B); ++I)
#define FOR(I, A, B) for(int I = (A); I >= (B) ; --I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define WI(X) printf("%d", (X))
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
const LL N=1e6+1, mod=1e9+7;
int sum, best; char a[N]; char bit[20] = "000000";
int main(){
   // home();
    RS(a);
  /*  REP(i, LEN(c)){
        a = a + " ";
        a[SZ(a) - 1] = c[SZ(a) - 1];
    }*/
    LL answer = 1;
    int n = LEN(a);
    REPP(i, 0, n - 1){
        //sum = 63;
       if (a[i] < '0') sum = 62;
        else if (a[i] <= '9') sum = a[i] - '0';
        else if(a[i] <= 'Z') sum = 10 + a[i] - 'A';
        else if(a[i] < 'a') sum = 63;
        else sum = 36 + a[i] - 'a';

        itoa(sum, bit, 2);
        //cout << bit << endl;
        REPP(i, 0, LEN(bit) - 1)
            if(bit[i] == '0'){
                answer *= 3;
                while(answer >= mod) answer -= mod;
            }

        REP(i, 6 - LEN(bit)){
            answer *= 3;
            while(answer >= mod) answer -= mod;
        }

        if(answer == 0){
            cout << 0;
            exit(0);
        }
    }


    cout << answer;
}