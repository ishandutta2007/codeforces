#include <cstdlib>
#include <cstdio>
#include <algorithm>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)

using namespace std;

int n, m, a;
int c[1010];

int main(){
    scanf("%d", &n);
    FWD(i,0,n){
        scanf("%d", &a);
        m = max(m, ++c[a]);
    }
    printf(m<=(n+1)/2?"YES":"NO");
    return 0;
}