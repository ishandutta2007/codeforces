#include <stdio.h>

int main(void) {
    int n;
    scanf("%d\n", &n);
    int a[20000];
    for(int i=0;i<n;i++) {
        scanf("%d\n", &a[i]);
    }
    int plus=0;
    for(int i=0;i<n;i++) {
        if (a[i]%2==0) {
            printf("%d\n", a[i]/2);
        }
        else {
        	if (a[i]>0) {
            printf("%d\n", a[i]/2+plus);
            plus=1-plus;
        	}
        	if (a[i]<0) {
        		printf("%d\n", a[i]/2+plus-1);
        		plus=1-plus;
        	}
        }
    }
    return 0;
}