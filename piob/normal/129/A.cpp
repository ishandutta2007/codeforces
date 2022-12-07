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

int e, o, n, a;

int main(){
    scanf("%d", &n);
    FWD(i,0,n){
        scanf("%d", &a);
        if(a&1)
            ++o;
        else
            ++e;
    }
    if(o&1)
        printf("%d\n", o);
    else
        printf("%d\n", e);
    return 0;
}