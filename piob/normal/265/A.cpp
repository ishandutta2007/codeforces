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

int n, p;
char A[64], B[64];

int main(){
    scanf("%s%s", A, B);
    n = strlen(B);
    p = 0;
    FWD(i,0,n)
        p += (A[p] == B[i]);
    printf("%d\n", p+1);
    return 0;
}