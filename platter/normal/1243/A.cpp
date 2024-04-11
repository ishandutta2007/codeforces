#include <cstdio>

int arr[1000];
int n;

int cando(int k) {
    int count=0;
    for(int i=0;i<n;i++) {
        if (arr[i]>=k) {
            count+=1;
        }
    }
    if (count>=k) {
        return 1;
    }
    return 0;
}

int main(void) {
    int c;
    scanf("%d\n",&c);
    for(int t=0;t<c;t++) {
        scanf("%d\n",&n);
        for(int i=0;i<n;i++) {
            scanf("%d ",&arr[i]);
        }
        scanf("\n");
        for(int i=n;i>0;i--) {
            if (cando(i)==1) {
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}