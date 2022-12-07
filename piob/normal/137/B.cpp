#include <cstdlib>
#include <cstdio>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)

using namespace std;

int n, a;
bool u[9100];

int main(){
    scanf("%d", &n);
    FWD(i,0,n){
        scanf("%d", &a);
        u[a] = 1;
    }
    a = 0;
    FWD(i,1,n+1)
        if(!u[i])
            ++a;
    printf("%d\n", a);
    return 0;
}