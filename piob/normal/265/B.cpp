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

int n, a, p, c;

int main(){
    scanf("%d", &n);
    FWD(i,0,n){
        scanf("%d", &a);
        c += 1 + abs(a - p);
        p = a;
    }
    printf("%d\n", c-1+n);
    return 0;
}