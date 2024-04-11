#include <cstdlib>
#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <functional>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define FE(a,b) for(typeof((b).end()) a=(b).begin(); a!=(b).end(); ++a)

using namespace std;

int n, k;
int A[64];

int main(){
    scanf("%d %d", &n, &k);
    FWD(i,1,n+1)
        scanf("%d", &A[i]);
    sort(A+1, A+n+1, greater<int>());
    if(k > n)
        printf("-1\n");
    else
        printf("%d %d\n", A[k], A[k]);
    return 0;
}