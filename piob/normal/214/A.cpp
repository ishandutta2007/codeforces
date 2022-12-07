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

int n, m, c;

int main(){
    scanf("%d %d", &n, &m);
    c = 0;
    FWD(i,0,100)
        FWD(j,0,100)
            if(i*i+j == n && j*j+i == m)
                ++c;
    printf("%d\n", c);
    return 0;
}