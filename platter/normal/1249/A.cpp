#include <cstdio>

int main(void) {
    int c;
    scanf("%d\n", &c);
    for(int t=0;t<c;t++) {
        int n;
        scanf("%d\n", &n);
        int a[100];
        for(int i=0;i<n;i++) {
            scanf("%d ", &a[i]);
        }
        scanf("\n");
        int check=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if (a[i]-a[j]==1||a[i]-a[j]==-1) {
                    check=1;
                }
            }
        }
        printf("%d\n", check+1);
    }
    return 0;
}