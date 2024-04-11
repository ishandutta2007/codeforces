#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define FE(a,b) for(typeof((b).end()) a=(b).begin(); a!=(b).end(); ++a)

using namespace std;

inline int gcd(int a, int b){
    while(a&&b) a>b?a%=b:b%=a;
    return a+b;
}

int main(){
    int n, f[2], t = 0, g;
    scanf("%d %d %d", &f[0], &f[1], &n);
    while(1){
        g = gcd(f[t], n);
        t = 1 - t;
        if(g > n){
            printf("%d\n", t);
            return 0;
        }
        n -= g;
    }
}