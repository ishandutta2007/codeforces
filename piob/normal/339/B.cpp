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

long long n, m, d, p;
long long A[100010];

int main(){
    scanf("%lld %lld", &n, &m);
    FWD(i,0,m)
        scanf("%lld", &A[i]);
    d = 0;
    p = 0;
    FWD(i,0,m){
        d += (A[i] - 1 - p + n) % n;
        p = A[i] - 1;
    }
    printf("%lld\n", d);
    return 0;
}