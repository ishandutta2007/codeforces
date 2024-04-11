#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define FE(a,b) for(typeof((b).end()) a=(b).begin(); a!=(b).end(); ++a)

using namespace std;

int n, m, r, c;
char T[110][20010];
int L[110][20010];
int R[110][20010];

int main(){
    scanf("%d %d", &n, &m);
    FWD(i,0,n){
        scanf("%s", T[i]);
        FWD(j,0,m) T[i][j+m] = T[i][j];
    }
    m *= 2;
    FWD(i,0,n){
        L[i][0] = 1000005;
        FWD(j,1,m) L[i][j] = (T[i][j] == '1'?0:L[i][j-1]+1);
        R[i][m-1] = 1000005;
        BCK(j,m-2,-1) R[i][j] = (T[i][j] == '1'?0:R[i][j+1]+1);
    }
    r = 1000005;
    FWD(j,0,m){
        c = 0;
        FWD(i,0,n) c += min(L[i][j], R[i][j]);
        r = min(r, c);
    }
    if(r == 1000005) r = -1;
    printf("%d\n", r);
    return 0;
}