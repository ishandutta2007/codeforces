#include <cstdio>

int main(void) {
    int c;
    scanf("%d\n",&c);
    for(int t=0;t<c;t++) {
        int a,b;
        scanf("%d %d\n",&a,&b);
        int diff=a-b;
        if (diff<0) {
            diff=-diff;
        }
        int val=0;
        while (1) {
            if (((val*(val+1))/2)%2==diff%2&&(val*(val+1))/2>=diff) {
                printf("%d\n",val);
                break;
            }
            val+=1;
        }
    }
    return 0;
}