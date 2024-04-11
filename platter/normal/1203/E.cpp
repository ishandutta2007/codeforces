#include <cstdio>

int cnt[150001];
bool check[150002];

int main(void) {
    int n;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++) {
        int x;
        scanf("%d ",&x);
        cnt[x]++;
    }
    if (cnt[1]==1) {
        check[1]=true;
    }
    if (cnt[1]>=2) {
        check[1]=true;
        check[2]=true;
    }
    for(int i=2;i<=150000;i++) {
        int put=0;
        for(int j=i-1;j<=i+1;j++) {
            if ((!check[j])&&put<cnt[i]) {
                check[j]=true;
                put++;
            }
        }
    }
    int ret=0;
    for(int i=1;i<=150001;i++) {
        if (check[i]) {
            ret++;
        }
    }
    printf("%d",ret);
    return 0;
}