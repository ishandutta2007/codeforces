#include <cstdio>

int main(void) {
    int c;
    scanf("%d\n",&c);
    for(int t=0;t<c;t++) {
        int n;
        scanf("%d\n",&n);
        int arr[200];
        int ind;
        for(int i=0;i<n;i++) {
            scanf("%d ",&arr[i]);
            if (arr[i]==1) {
                ind=i;
            }
        }
        scanf("\n");
        bool flag=true;
        int num=1;
        bool temp=true;
        for(int i=0;i<n;i++) {
            if (arr[(i+ind)%n]!=num) {
                flag=false;
                break;
            }
            temp=false;
            num++;
        }
        if (flag) {
            printf("YES\n");
            continue;
        }
        flag=true;
        num=1;
        temp=false;
        for(int i=n;i>0;i--) {
            if (arr[(i+ind)%n]!=num) {
                flag=false;
                break;
            }
            temp=false;
            num++;
        }
        if (flag)  {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }
    return 0;
}