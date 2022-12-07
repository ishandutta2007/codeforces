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

int n, a;
int P[110];

int main(){
    scanf("%d", &n);
    FWD(i,0,n){
        scanf("%d", &a);
        P[a] = i+1;
    }
    FWD(i,1,n+1)
        printf("%d ", P[i]);
    printf("\n");
    return 0;
}