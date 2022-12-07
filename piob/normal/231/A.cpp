#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define FE(a,b) for(typeof((b).end()) a=(b).begin(); a!=(b).end(); ++a)

using namespace std;

int main(){
    int n, a, b, c, d = 0;
    scanf("%d", &n);
    FWD(i,0,n){
        scanf("%d %d %d", &a, &b, &c);
        if(a + b + c > 1)
            ++d;
    }
    printf("%d\n", d);
    return 0;
}