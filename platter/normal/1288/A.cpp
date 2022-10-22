#include <cstdio>
#include <cmath>

int main(void) {
    int c;
    scanf("%d\n",&c);
    for(int t=0;t<c;t++) {
        int n,d;
        scanf("%d %d\n",&n,&d);
        int x=sqrt(d)-1;
        if (x+(d-1)/(x+1)+1<=n)  {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }
    return 0;
}