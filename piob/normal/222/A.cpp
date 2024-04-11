#include <cstdlib>
#include <cstdio>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)

using namespace std;

int n, k, p;
int a[100010];

int main(){
    scanf("%d %d", &n, &k);
    FWD(i,1,n+1)
        scanf("%d", &a[i]);
    p = 0;
    FWD(i,1,n+1)
        if(a[i] != a[k])
            p = i;
    if(p > k)
        printf("-1\n");
    else
        printf("%d\n", p);
    return 0;
}