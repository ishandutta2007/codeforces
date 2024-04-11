#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <string>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define FE(a,b) for(typeof((b).end()) a=(b).begin(); a!=(b).end(); ++a)
#define PACKS(a) int a;scanf("%d",&a);++a;while(--a)
#define PII pair<int, int>
#define x first
#define y second

using namespace std;

int n, k, r;
PII P[4010];
int R[4010][4010];

int main(){
    scanf("%d %d", &n, &k);
    FWD(i,1,n+1)
        scanf("%d %d", &P[i].x, &P[i].y);
    sort(P+1, P+n+1);
    FWD(i,0,k+1)
        R[0][i] = 1;
    r = 0;
    FWD(i,1,n+1){
        R[i][0] = max(R[i-1][0], P[i].x) + P[i].y;
        FWD(j,1,k+1){
            R[i][j] = min(max(R[i-1][j], P[i].x) + P[i].y, R[i-1][j-1]);
        }
        r = max(r, P[i].x - R[i-1][k]);
    }
    r = max(r, 86401 - R[n][k]);
    printf("%d\n", r);
    return 0;
}