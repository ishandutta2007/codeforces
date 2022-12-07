#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define FE(a,b) for(typeof((b).end()) a=(b).begin(); a!=(b).end(); ++a)

using namespace std;

int n, a, b, h;
int H[210];
int R[210][40010][2];

int main(){
#ifdef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    scanf("%d %d %d", &n, &a, &b);
    FWD(i,1,n+1) scanf("%d", &H[i]);
    FWD(i,0,a) R[0][i][0] = R[0][i][1] = 1000000000;
    R[0][a][1] = 0;
    R[0][a][0] = 0;
    H[0] = 0;
    h = 0;
    FWD(i,1,n+1){
        FWD(c,0,a+1) R[i][c][0] = R[i][c][1] = 1000000000;
        FWD(c,0,a+1){
            if(H[i] <= c)
                R[i][c-H[i]][0] = min(R[i][c-H[i]][0], min(R[i-1][c][0], R[i-1][c][1]+min(H[i],H[i-1])));
            if(H[i] <= b-(h-(a-c)))
                R[i][c][1] = min(R[i][c][1], min(R[i-1][c][1], R[i-1][c][0]+min(H[i], H[i-1])));
        }
        //FWD(c,0,a+1) printf("%d %d\n", R[i][c][0], R[i][c][1]);
        //printf("\n");
        h += H[i];
    }
    int res = 1000000000;
    FWD(i,0,a+1) res = min(res, min(R[n][i][0], R[n][i][1]));
    printf("%d\n", res==1000000000?-1:res);
    return 0;
}