#include <cstdio>
 
int main(void) {
    int n;
    scanf("%d\n", &n);
    int stat=0;
    int total=0;
    for(int i=0;i<n;i++) {
        int temp;
        scanf("%d ", &temp);
        if (temp<0) {
            stat=1-stat;
        }
        if (stat==1) {
            total+=1;
        }
    }
    long long pre=total;
    long long ln=n;
    long long ans=total*(ln-total+1);
    long long x=(ln*(ln+1))/2;
    printf("%lld %lld", ans, x-ans);
    return 0;
}