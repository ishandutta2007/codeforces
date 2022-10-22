#include <cstdio>

int a[201];
int ans[201];
int booknow[201];
int bookstore[201];
int check[201];
int n;

void timego() {
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            booknow[a[j]]=bookstore[j];
        }
        for(int j=1;j<=n;j++) {
            bookstore[j]=booknow[j];
        }
        for(int j=1;j<=n;j++) {
            if (booknow[j]==j) {
                if (check[j]==0) {
                    ans[j]=i;
                    check[j]=1;
                }
            }
        }
    }
}

int main(void) {
    int c;
    scanf("%d\n", &c);
    for(int t=0;t<c;t++) {
        scanf("%d\n", &n);
        for(int i=1;i<=n;i++) {
            scanf("%d ", &a[i]);
            ans[i]=-1;
            booknow[i]=i;
            bookstore[i]=i;
            check[i]=0;
        }
        scanf("\n");
        timego();
        for(int i=1;i<=n;i++) {
            printf("%d ", ans[i]);
        }
        printf("\n");
    }
    return 0;
}