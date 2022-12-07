#include <cstdlib>
#include <cstdio>
#include <algorithm>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)

using namespace std;

int n, k;

int main(){
    scanf("%d %d", &n, &k);
    if(k > n || (n > 1 && k == 1))
        printf("-1\n");
    else{
        FWD(i,0,min(n,n-k+2))
            printf((i&1)?"b":"a");
        FWD(i,n-k+2,n)
            printf("%c", 'c'+i-(n-k+2));
    }
    printf("\n");
    return 0;
}