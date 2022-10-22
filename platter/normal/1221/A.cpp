#include <stdio.h>
 
int main(void) {
    int c;
    scanf("%d\n", &c);
    for(int t=0;t<c;t++) {
        int n;
        scanf("%d\n", &n);
        int arr[12]={};
        int a;
        int k;
        for(int i=0;i<n;i++) {
            int k=1;
            scanf("%d ", &a);
            if (a<=2048) {
                for(int j=0;j<=11;j++) {
                    if (k==a) {
                        arr[j]+=1;
                    }
                    k=k*2;
                }
            }
        }
        scanf("\n");
        for(int i=0;i<11;i++) {
            arr[i+1]+=arr[i]/2;
        }
        if (arr[11]>=1) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }
    return 0;
}