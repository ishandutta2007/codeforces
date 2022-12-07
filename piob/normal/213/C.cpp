#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cstring>
#include <set>
#include <stack>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define FE(a,b) for(__typeof((b).end()) a=(b).begin(); a!=(b).end(); ++a)
#define PII pair<int, int>
#define PDD pair<long double, long double>
#define x first
#define y second
#define EPS 1e-9
#define INF 1000000009

using namespace std;

int n;
int P[310][310];
int R[610][310][310];

inline bool in(int a){
    return 0<=a && a<n;
}

inline bool valid(int c, int a, int b){
    return in(a) && in(c-a) && in(b) && in(c-b);
}

int main(){
    scanf("%d", &n);
    FWD(i,0,n)
        FWD(j,0,n)
            scanf("%d", &P[i][j]);
    if(n == 1){
        printf("%d\n", P[0][0]);
        return 0;
    }
    FWD(i,0,2*n-1)
        FWD(j,0,n)
            FWD(k,0,n)
                R[i][j][k] = -INF;
    R[0][0][0] = P[0][0];
    FWD(c,1,2*n-1){
        FWD(a,0,min(c+1,n))
            FWD(b,0,min(c+1,n)){
                if(!valid(c,a,b)) continue;
                if(valid(c-1,a,b)) R[c][a][b] = max(R[c][a][b], R[c-1][a][b]);
                if(valid(c-1,a,b-1)) R[c][a][b] = max(R[c][a][b], R[c-1][a][b-1]);
                if(valid(c-1,a-1,b)) R[c][a][b] = max(R[c][a][b], R[c-1][a-1][b]);
                if(valid(c-1,a-1,b-1)) R[c][a][b] = max(R[c][a][b], R[c-1][a-1][b-1]);
                if(a != b)
                    R[c][a][b] += P[a][c-a] + P[b][c-b];
                else
                    R[c][a][b] += P[a][c-a];
            }
    }
    printf("%d\n", R[2*n-2][n-1][n-1]);
    return 0;
}