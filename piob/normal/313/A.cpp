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

int n, a, b;

int main(){
    scanf("%d", &n);
    if(n > 0)
        printf("%d\n", n);
    else{
        n = -n;
        a = n % 10;
        n /= 10;
        b = n % 10;
        n /= 10;
        n = n * 10 + min(a, b);
        printf("%d\n", -n);
    }
    return 0;
}