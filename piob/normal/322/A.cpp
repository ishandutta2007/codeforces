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

int n, m;

int main(){
    scanf("%d %d", &n, &m);
    printf("%d\n", n+m-1);
    FWD(i,1,m+1)
        printf("1 %d\n", i);
    FWD(i,2,n+1)
        printf("%d 1\n", i);
    return 0;
}