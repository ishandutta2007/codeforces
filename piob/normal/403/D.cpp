#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define REP(a,b) for(int a=0; a<(b); ++a)
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FWDS(a,b,c,d) for(int a=(b); a<(c); a+=d)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define ALL(a) (a).begin(), (a).end()
#define SORT(a) sort(ALL(a))
#define UNIQUE(a) a.erase(unique(ALL(a)), (a).end())
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define re real()
#define im imag()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef double K;
typedef vector<int> VI;

//int dx[] = {0,0,-1,1}; //,1,1,-1,-1}; //,0};
//int dy[] = {-1,1,0,0}; //,1,-1,1,-1}; //,0};

inline int gcd(int a, int b){ while(a&&b) a>b?a%=b:b%=a; return a+b; }

const LL MOD = 1000000007;

const int MAXN = 2010;

//L[n][k] to liczba k-elementowych podzbiorow sumujacych sie do n
LL P[MAXN][MAXN]; 

//;P(n,k) == S(n+(k*(k-1)/2),k)

LL S(int n, int k){
    if(n < k*(k-1)/2)
        return 0;
    //printf("%d %d %d\n", n, n-k*(k-1)/2, k);
    //printf("  %lld\n", P[n-k*(k-1)/2][k]);
    return P[n-k*(k-1)/2][k];
}

LL S0(int n, int k){
    return S(n,k) + S(n,k-1);
}

//Newton
LL N[MAXN][MAXN];

LL SIL[MAXN];

//wynik(n,k) = sum s[0..n-k] * k! * 
//suma po |k|-podzbiorach sumujacych sie do <= n-k (k! * (podzial(i) na k+1))

/*
3 2
(1,1) (2,3)
(1,2) (3,3)


S(1,2) 
    n = 1
    k = 2
    k*(k-1)/2 = 1
    P[0][1] + P[0][0]
*/

int main(){
    P[0][0] = 1;
    SIL[0] = 1;
    FWD(n,1,MAXN){
        P[n][n] = 1;
        N[n][0] = N[n][n] = 1;
        SIL[n] = SIL[n-1] * n % MOD;
        FWD(k,1,n)
            N[n][k] = (N[n-1][k] + N[n-1][k-1]) % MOD;
        FWD(k,1,min(n,100)){
            FWD(i,1,k+1)
                P[n][k] += P[n-k][i];
            P[n][k] %= MOD;
        }       
    }
    /*FWD(n,0,20){
        FWD(k,0,20)
            printf("%lld ", S0(n,k));
        printf("\n");
    }*/
    int z; scanf("%d", &z); while(z--){
        int n, k;
        scanf("%d %d", &n, &k);
        //printf("%d %d\n", n, k);
        LL res = 0;
        FWD(i,0,n-k+1){
            /*printf("roznice sumujace sie do %d\n", i);
            printf("    liczba takich roznic %lld", S0(i,k));
            printf("    permutacje %lld\n", SIL[k]);
            printf("    dodatki %lld\n", N[n-k-i+k][k]);*/
            res = (res + S0(i,k) * SIL[k] % MOD * N[n-k-i+k][k]) % MOD;
        }
        printf("%d\n", (int) res);
    }
    return 0;
}