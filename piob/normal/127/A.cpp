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

int n, k;
int a, b, c, d;
double ds;

int main(){
    scanf("%d %d", &n, &k);
    scanf("%d %d", &a, &b);
    FWD(i,1,n){
        scanf("%d %d", &c, &d);
        ds += sqrt(p2(a-c)+p2(b-d));
        a = c;
        b = d;
    }
    printf("%lf\n", ds/50*k);
    return 0;
}