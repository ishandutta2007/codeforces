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
#define p2(a) ((a)*(a))

using namespace std;

int n, a, b;
int D[110];

int main(){
    scanf("%d", &n);
    FWD(i,1,n){
        scanf("%d", &D[i]);
        D[i] += D[i-1];
    }
    scanf("%d %d", &a, &b);
    printf("%d\n", D[b-1] - D[a-1]);
    return 0;
}