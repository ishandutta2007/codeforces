#include <bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define WI(X) printf("%d ", (X))
#define WII(X, Y) printf("%d%d", (X), (Y))
#define WIII(X, Y, Z) printf("%d%d%d", (X), (Y), (Z))
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
#define IS insert
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 2e5+10;
void home(){
    freopen("AVERAGES.INP","r",stdin);
    freopen("AVERAGES.OUT","w",stdout);
}
double s,GET[SIZE],GT[SIZE],res;
int x,y,z,luu[SIZE],n=1,sl;
void solve(){
   // cout<<fixed;
    RI(sl);
    REP(i,sl){
        RI(x);
        if(x==1){
            RII(y,z);
            s+=double(y)*z;
            GET[y]+=z;
        }
        else if(x==2){
            RI(y);n++;
            GT[n]=y;
            s+=y;
        }
        else {
            if(n>=2){
            s-=GET[n]+GT[n];
            GET[n-1]+=GET[n];
            GET[n]=0;
            n--;
         }
       }
       //cout<<s<<" "<<n<<" ";
        res=s/n;
        printf("%.6lf\n", res);
    }
}
int main(){
    //home();
    solve();
    return 0;
}