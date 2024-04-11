#include <stdio.h>

int main() {
    int c;
    scanf("%d\n", &c);
    for(int t=0;t<c;t++) {
        int n;
        scanf("%d\n", &n);
        int arr[100]={};
        for(int i=0;i<n;i++) {
            scanf("%d ", &arr[i]);
        }
        scanf("\n");
        int total=0;
        for(int i=0;i<n;i++) {
            total+=arr[i];
        }
        int ans=((total-1)/n)+1;
        printf("%d\n", ans);
    }
    return 0;
}