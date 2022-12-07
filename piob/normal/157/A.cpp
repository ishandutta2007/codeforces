#include <cstdlib>
#include <cstdio>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)

using namespace std;

int n, c;
int C[32];
int R[32];
int M[32][32];

int main(){
    scanf("%d", &n);
    FWD(i,0,n)
        FWD(j,0,n){
            scanf("%d", &M[i][j]);
            R[i] += M[i][j];
            C[j] += M[i][j];
        }
    FWD(i,0,n)
        FWD(j,0,n)
            if(C[j] > R[i])
                ++c;
    printf("%d\n", c);
    return 0;
}