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

int A[3];
int n, a;

int main(){
    scanf("%d", &n);
    FWD(i,0,n){
        scanf("%d", &a);
        A[i%3] += a;
    }
    if(A[0] > A[1] && A[0] > A[2])
        printf("chest\n");
    else if(A[1] > A[2])
        printf("biceps\n");
    else
        printf("back\n");
    return 0;
}