#include <bits/stdc++.h>
#define REP(a,b) for(int a=0; a<(b); ++a)
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FWDS(a,b,c,d) for(int a=(b); a<(c); a+=d)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second
#define pb push_back
#define re real()
#define im imag()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef double K;
typedef vector<int> VI;

int n;
int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
int result[102][(1<<16) + 3];
int prv[102][(1<<16) + 3];
int mt[63];

int make(int x){
    int m = 0;
    int c = 0;
    while(x > 1){
        while(x % primes[c] == 0){
            m |= (1 << c);
            x /= primes[c];
        }
        ++c;
    }
    return m;
}

int main(){
    FWD(b,1,59) mt[b] = make(b);
    scanf("%d", &n);
    FWD(i,0,n){
        int a;
        scanf("%d", &a);
        FWD(m,0,1<<16) result[i+1][m] = 1e9;
        FWD(b,1,59){
            FWD(m,0,1<<16){
                int k = mt[b];
                if(k&m) continue;
                k |= m;
                if(result[i+1][k] > result[i][m] + abs(a-b)){
                    result[i+1][k] = result[i][m] + abs(a-b);
                    prv[i+1][k] = b;
                }
            }
        }
    }
    int r = 1e9;
    int bm = 0;
    FWD(m,0,1<<16){
        if(r > result[n][m]){
            r = result[n][m];
            bm = m;
        }
    }
    stack<int> S;
    BCK(i,n,0){
        S.push(prv[i][bm]);
        bm &= ~mt[S.top()];
    }
    for(;!S.empty();S.pop()) printf("%d ", S.top());
    S.pop();
    return 0;
}