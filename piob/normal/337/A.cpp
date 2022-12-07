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

int n, m, b;
int S[64];

int main(){
    scanf("%d %d", &n, &m);
    FWD(i,0,m)
        scanf("%d", &S[i]);
    sort(S, S+m);
    b = S[n-1] - S[0];
    FWD(i,0,m-n+1)
        b = min(b, S[i+n-1] - S[i]);
    printf("%d\n", b);
    return 0;
}