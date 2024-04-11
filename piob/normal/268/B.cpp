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

//(n - 1) + 2 * (n - 2) + 3 * (n-3) + ... + n

int main(){
    int n, s = 0;
    scanf("%d", &n);
    FWD(i,1,n)
        s += i * (n-i);
    printf("%d\n", s + n);
    return 0;
}