#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define FE(a,b) for(typeof((b).end()) a=(b).begin(); a!=(b).end(); ++a)
#define PACKS(a) int a;scanf("%d",&a);++a;while(--a)
#define PLL pair<long long, long long>
#define x first
#define y second

using namespace std;

int n, k, r;
int T[64];

int main(){
    scanf("%d %d", &n, &k);
    r = 0;
    FWD(i,0,n)
        scanf("%d", &T[i]);
    T[n] = 0;
    while(T[r] >= max(T[k-1], 1))
        ++r;
    printf("%d\n", r);
    return 0;
}