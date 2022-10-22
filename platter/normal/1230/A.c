#include <stdio.h>

int main(void) {
    int a[4]={};
    int total=0;
    for(int i=0;i<4;i++) {
        scanf("%d ", &a[i]);
        total+=a[i];
    }
    if (total%2==1) {
        printf("NO");
        return 0;
    }
    int x=total/2;
    for(int i=0;i<4;i++) {
        if (a[i]==x) {
            printf("YES");
            return 0;
        }
    }
    for(int i=0;i<3;i++) {
        for(int j=i+1;j<4;j++) {
            if (a[i]+a[j]==x) {
                printf("YES");
                return 0;
            }
        }
    }
    printf("NO");
    return 0;
}