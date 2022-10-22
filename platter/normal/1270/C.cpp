#include <cstdio>

int main(void) {
    int c;
    scanf("%d\n",&c);
    for(int t=0;t<c;t++) {
        int n;
        scanf("%d\n",&n);
        long long total=0;
        long long xtotal=0;
        for(int i=0;i<n;i++) {
            long long x;
            scanf("%lld ",&x);
            total+=x;
            xtotal^=x;
        }
        printf("2\n");
        printf("%lld ",xtotal);
        total+=xtotal;
        xtotal^=xtotal;
        printf("%lld\n",total);
    }
    return 0;
}