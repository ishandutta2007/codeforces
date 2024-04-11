#include <stdio.h>
#include <algorithm>
using namespace std;

int main(void) {
    int c;
    scanf("%d\n", &c);
    for(int t=0;t<c;t++) {
        int n;
        scanf("%d\n", &n);
        int minimum=n;
        for(int i=0;i<n;i++) {
            int x;
            scanf("%1d", &x);
            if (x==1) {
                minimum=min(min(i,n-1-i),minimum);
            }
        }
        printf("%d\n", max((n-minimum)*2,n));
    }
    return 0;
}