#include <cstdio>

int main(void) {
    int c;
    scanf("%d\n",&c);
    for(int t=0;t<c;t++) {
        int n;
        scanf("%d\n",&n);
        int prev;
        scanf("%d ",&prev);
        int ret=0;
        for(int i=1;i<n;i++) {
            int x;
            scanf("%d ",&x);
            if (x-prev>1||x-prev<-1) {
                ret=i;
            }
            prev=x;
        }
        scanf("\n");
        if (ret) {
            printf("YES\n");
            printf("%d %d\n",ret,ret+1);
        }
        else {
            printf("NO\n");
        }
    }
    return 0;
}