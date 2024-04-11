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

int k, n;
char buff[1024];
int N[256];

int main(){
    scanf("%d%s", &k, buff);
    n = strlen(buff);
    FWD(i,0,n)
        ++N[buff[i]];
    FWD(i,'a','z'+1)
        if(N[i] % k){
            printf("-1\n");
            return 0;
        }
    FWD(r,0,k)
        FWD(i,'a','z'+1)
            FWD(j,0,N[i]/k)
                printf("%c", i);
    printf("\n");
    return 0;
}