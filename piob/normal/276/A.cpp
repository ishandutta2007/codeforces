#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <functional>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define FE(a,b) for(typeof((b).end()) a=(b).begin(); a!=(b).end(); ++a)

using namespace std;

int n, k, a, b, m;

int main(){
    scanf("%d %d", &n, &k);
    m = -2000100000;
    FWD(i,0,n){
        scanf("%d %d", &a, &b);
        m = max(m, min(a, a+k-b));
    }
    printf("%d\n", m);
    return 0;
}