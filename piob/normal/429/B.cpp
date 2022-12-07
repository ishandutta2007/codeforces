#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

int n, m;
int T[1010][1010];
int A[1010][1010];
int B[1010][1010];
int C[1010][1010];
int D[1010][1010];

int main(){
    scanf("%d %d", &n, &m);
    FWD(i,1,n+1)
        FWD(j,1,m+1)
            scanf("%d", &T[i][j]);

    FWD(i,1,n+1)
        FWD(j,1,m+1)
            A[i][j] = T[i][j] + max(A[i-1][j], A[i][j-1]);
    BCK(i,n,0)
        BCK(j,m,0)
            B[i][j] = T[i][j] + max(B[i+1][j], B[i][j+1]);
    BCK(i,n,0)
        FWD(j,1,m+1)
            C[i][j] = T[i][j] + max(C[i+1][j], C[i][j-1]);
    FWD(i,1,n+1)
        BCK(j,m,0)
            D[i][j] = T[i][j] + max(D[i-1][j], D[i][j+1]);
    int r = 0;
    FWD(i,2,n)
        FWD(j,2,m){
            r = max(r, A[i-1][j] + B[i+1][j] + C[i][j-1] + D[i][j+1]);
            r = max(r, A[i][j-1] + B[i][j+1] + C[i+1][j] + D[i-1][j]);
        }
    printf("%d\n", r);
    return 0;
}