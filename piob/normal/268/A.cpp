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

int n, c;
int A[32], B[32];

int main(){
    c = 0;
    scanf("%d", &n);
    FWD(i,0,n)
        scanf("%d %d", &A[i], &B[i]);
    FWD(i,0,n)
        FWD(j,0,n)
            if(A[i] == B[j])
                ++c;
    printf("%d\n", c);
    return 0;
}