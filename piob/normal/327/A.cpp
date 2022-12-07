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

int n, a, c, t, b;

int main(){
    t = b = 0;
    scanf("%d", &n);
    FWD(i,0,n){
        scanf("%d", &a);
        c = max(0, c - 2*a + 1);
        t += a;
        b = max(b, c);
    }
    if(t == n)
        printf("%d\n", n-1);
    else
        printf("%d\n", t+b);
    return 0;
}