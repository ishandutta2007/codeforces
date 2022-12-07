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

const int MAXP = 2000010;

int n, m;
int R[MAXP];
int D[MAXP];
int G[5010];
int A[5010];
int B[5010];

int rate(int x){
    int d = 2;
    int r = 0;
    while(x >= MAXP && d*d <= x){
        while(x%d == 0){
            r += R[d];
            x /= d;
        }
        ++d;
    }
    if(x >= MAXP)
        r += binary_search(B, B+m, x)?-1:1;
    else
        r += R[x];
    return r;
}

int main(){
    scanf("%d %d", &n, &m);
    FWD(i,0,n) scanf("%d", &A[i]);
    FWD(i,0,n) scanf("%d", &B[i]);
    int b = 0;
    R[1] = 0;
    int lim = sqrt(MAXP+3)+3;
    FWD(i,2,MAXP){
        if(D[i] == 0){
            if(b < m && i == B[b]){
                R[i] = -1;
                ++b;
            }else
                R[i] = 1;
            if(i < lim)
                for(int j = i*i; j < MAXP; j+=i)
                    D[j] = i;
        }else
            R[i] = R[i/D[i]] + R[D[i]];
    }
    G[0] = A[0];
    FWD(i,1,n){
        G[i] = gcd(G[i-1], A[i]);
    }
    //FWD(i,1,30) printf("%d : %d\n", i, rate(i));
    int g = 1;
    int r = 0, pr, rg = 0;
    int s = 0;
    G[n] = 1;
    BCK(i,n-1,-1){
        pr = rate(G[i]/g);
        if(pr < 0){
            g = G[i];
            rg += pr;
        }
        //printf("wydzielamy przez %d (%d)\n", g, rg);
        r += rate(G[i]/G[i+1]);
        //printf("doliczamy kare za %d = %d\n", A[i], rate(A[i]/G[i]) + r);
        s += rate(A[i]/G[i]) + r - rg;
        A[i] /= g;
    }
    printf("%d\n", s);
    return 0;
}