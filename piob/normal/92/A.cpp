#include <cstdlib>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <functional>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define FE(a,b) for(typeof((b).end()) a=(b).begin(); a!=(b).end(); ++a)

using namespace std;

int n, m;

int main(){
    scanf("%d %d", &n, &m);
    m %= n * (n + 1) / 2;
    FWD(i,1,n+1)
        if(m >= i)
            m -= i;
    printf("%d\n", m);
    return 0;
}