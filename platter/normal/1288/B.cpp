#include <cstdio>

int arr[9]={9,99,999,9999,99999,999999,9999999,99999999,999999999};

int count(long long n) {
    int ret=0;
    for(int i=0;i<9;i++) {
        if (arr[i]>n) {
            return i;
        }
    }
    return 9;
}

int main(void) {
    int c;
    scanf("%d\n",&c);
    for(int t=0;t<c;t++) {
        long long a,b;
        scanf("%lld %lld\n",&a,&b);
        printf("%lld\n",a*count(b));
    }
    return 0;
}