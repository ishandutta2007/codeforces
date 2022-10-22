#include <cstdio>

int main(void) {
    int r,c;
    scanf("%d %d",&r,&c);
    long long arr[500][500];
    if (r==1&&c==1) {
        printf("0");
        return 0;
    }
    else if (r==1) {
        for(int i=0;i<c;i++) {
            arr[0][i]=i+2;
        }
    }
    else if (c==1) {
        for(int i=0;i<r;i++) {
            arr[i][0]=i+2;
        }
    }
    else {
        for(long long i=0;i<r;i++) {
            for(long long j=0;j<c;j++) {
                arr[i][j]=(i+1)*(j+r+1);
            }
        }
    }
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            printf("%lld ",arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}