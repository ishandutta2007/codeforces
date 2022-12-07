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

long long a, b, p;

int main(){
    scanf("%lld%lld", &a, &b);
    int c = 0;
    p = a;
    while(p < b){
        p *= a;
        ++c;
    }
    if(p == b)
        printf("YES\n%d\n", c);
    else
        printf("NO\n");
    return 0;
}