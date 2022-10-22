#include <cstdio>

int main(void) {
    int n;
    scanf("%d",&n);
    double ret=0;
    for(int i=1;i<=n;i++) {
        ret+=1.0/i;
    }
    printf("%.12lf",ret);
}