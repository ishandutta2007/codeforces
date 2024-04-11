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

//(n - 1) + 2 * (n - 2) + 3 * (n-3) + ... + n

int main(){
    int n;
    scanf("%d", &n);
    FWD(i,0,n+1){
        FWD(j,0,2*(n-i)) printf(" ");
        FWD(j,0,i+1){
            printf("%d", j);
            if(j != i) printf(" ");
        }
        BCK(j,i-1,-1) printf(" %d", j);
        printf("\n");
    }
    BCK(i,n-1,-1){
        FWD(j,0,2*(n-i)) printf(" ");
        FWD(j,0,i+1){
            printf("%d", j);
            if(j != i) printf(" ");
        }
        BCK(j,i-1,-1) printf(" %d", j);
        printf("\n");
    }
    return 0;
}