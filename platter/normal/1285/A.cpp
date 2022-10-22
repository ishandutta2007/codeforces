#include <cstdio>

int main(void) {
    int n;
    scanf("%d\n",&n);
    int lcnt=0;
    int rcnt=0;
    for(int i=0;i<n;i++) {
        char x;
        scanf("%c",&x);
        if (x=='L') {
            lcnt++;
        }
        else {
            rcnt++;
        }
    }
    printf("%d",lcnt+rcnt+1);
    return 0;
}