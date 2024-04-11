#include <cstdio>

int main(void) {
    int n;
    scanf("%d\n", &n);
    for(int i=0;i<n;i++) {
        int c,s;
        scanf("%d %d\n",&c,&s);
        int ret=0;
        while (c>0) {
            int x=s/c;
            ret+=x*x;
            s-=x;
            c-=1;
        }
        printf("%d\n",ret);
    }
    return 0;
}