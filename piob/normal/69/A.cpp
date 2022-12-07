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

int n, a, b, c, x, y, z;

int main(){
    scanf("%d", &n);
    a = b = c = 0;
    FWD(i,0,n){
        scanf("%d %d %d", &x, &y, &z);
        a += x, b += y, c += z;
    }
    printf(a == b && b == c && c == 0 ? "YES" : "NO");
    return 0;
}