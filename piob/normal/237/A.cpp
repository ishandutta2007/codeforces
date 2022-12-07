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

int n, a, b, c, m, x, y;

int main(){
    scanf("%d", &n);
    a = -1;
    m = 0;
    c = 1;
    FWD(i,0,n){
        scanf("%d %d", &x, &y);
        b = x * 60 + y;
        if(a == b)
            ++c;
        else
            c = 1;
        m = max(m, c);
        a = b;
    }
    printf("%d\n", m);
    return 0;
}