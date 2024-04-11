#include <cstdio>

int main(void) {
    int c;
    scanf("%d\n", &c);
    bool check[100001];
    int arr[100000];
    int ret[100000];
    for(int t=0;t<c;t++) {
        int n;
        scanf("%d\n", &n);
        for(int i=1;i<=n;i++) {
            check[i]=false;
        }
        for(int i=0;i<n;i++) {
            scanf("%d ", &arr[i]);
            check[arr[i]]=true;
        }
        scanf("\n");
        int now=1;
        int prev=0;
        bool flag=true;
        for(int i=0;i<n;i++) {
            if (arr[i]>prev) {
                ret[i]=arr[i];
                prev=arr[i];
            }
            else {
                while (1) {
                    if (!check[now]) {
                        ret[i]=now;
                        check[now]=true;
                        break;
                    }
                    now+=1;
                }
                if (now>arr[i]) {
                    printf("-1\n");
                    flag=false;
                    break;
                }
            }
        }
        if (flag) {
            for(int i=0;i<n;i++) {
                printf("%d ", ret[i]);
            }
            printf("\n");
        }
    }
    return 0;
}