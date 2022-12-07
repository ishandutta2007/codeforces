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

int n;
long long c;
int P[300010];

int main(){
    scanf("%d", &n);
    FWD(i,0,n)
        scanf("%d", &P[i]);
    sort(P, P+n);
    FWD(i,0,n)
        c += abs(P[i]-i-1);
    printf("%lld\n", c);
    return 0;
}