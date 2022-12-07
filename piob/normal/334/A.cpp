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

int n;
int main(){
    scanf("%d", &n);
    FWD(i,0,n){
        FWD(j,0,n/2)
            printf("%d ", i*n/2+j+1);
        FWD(j,0,n/2)
            printf("%d ", n*n-i*n/2-j);
        printf("\n");
    }
    return 0;
}