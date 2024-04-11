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
#define p2(a) ((a)*(a))

using namespace std;

int n, m, c;
int A[100010];

int main(){
    scanf("%d", &n);
    FWD(i,0,n)
        scanf("%d", &A[i]);
    m = *min_element(A, A+n);
    FWD(i,0,n)
        if(A[i] == m)
            ++c;
    if(c == 1){
        FWD(i,0,n)
            if(A[i] == m)
                printf("%d\n", i+1);
    }else
        printf("Still Rozdil\n");
    return 0;
}