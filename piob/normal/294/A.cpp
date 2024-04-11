#include <cstdlib>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <functional>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define FE(a,b) for(typeof((b).end()) a=(b).begin(); a!=(b).end(); ++a)

using namespace std;

int A[128];
int n, k, x, y;

int main(){
    scanf("%d", &n);
    FWD(i,1,n+1)
        scanf("%d", &A[i]);
    scanf("%d", &k);
    FWD(i,0,k){
        scanf("%d %d", &x, &y);
        A[x-1] += y - 1;
        A[x+1] += A[x] - y;
        A[x] = 0;
    }
    FWD(i,1,n+1)
        printf("%d\n", A[i]);
    return 0;
}