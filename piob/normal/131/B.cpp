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

int n, a;
int X[64];
long long c;

int main(){
    scanf("%d", &n);
    FWD(i,0,n){
        scanf("%d", &a);
        ++X[a+32];
    }
    FWD(i,1,12)
        c += ((long long)X[32-i]) * X[32+i];
    c += ((long long)X[32]) * (X[32] - 1) / 2;
    printf("%lld\n", c);
    return 0;
}