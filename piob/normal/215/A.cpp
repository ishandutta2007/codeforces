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

int n, m, r, c;
int A[64], B[64];

int main(){
    scanf("%d", &n);
    FWD(i,0,n)
        scanf("%d", &A[i]);
    scanf("%d", &m);
    FWD(i,0,m)
        scanf("%d", &B[i]);
    r = c = 0;
    FWD(i,0,n)
        FWD(j,0,m)
            if(B[j] % A[i] == 0)
                r = max(r, B[j] / A[i]);
    FWD(i,0,n)
        FWD(j,0,m)
            if(B[j] % A[i] == 0)
                if(r == B[j] / A[i])
                    ++c;
    printf("%d\n", c);
    return 0;
}