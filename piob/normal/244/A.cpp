#include <cstdlib>
#include <cstdio>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)

using namespace std;

int n, k, p;
bool u[1024];
int a[64];

int main(){
    scanf("%d %d", &n, &k);
    FWD(i,0,k){
        scanf("%d", &a[i]);
        u[a[i]] = 1;
    }
    p = 1;
    FWD(i,0,k){
        printf("%d", a[i]);
        FWD(i,1,n){
            while(u[p]) ++p;
            printf(" %d", p++);
        }
        printf("\n");
    }
    return 0;
}