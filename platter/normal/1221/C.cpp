#include <stdio.h>
#include <algorithm>

using namespace std;

int main(void) {
    int c;
    scanf("%d\n", &c);
    for(int t=0;t<c;t++) {
        int c,m,x;
        scanf("%d %d %d\n", &c, &m, &x);
        int ans=min((c+m+x)/3,min(c,m));
        printf("%d\n", ans);
    }
    return 0;
}