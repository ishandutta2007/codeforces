#include <cstdio>
#include <algorithm>
using namespace std;

int main(void) {
    int c;
    scanf("%d\n",&c);
    for(int t=0;t<c;t++) {
        int n,a,b;
        scanf("%d %d %d\n",&n,&a,&b);
        int maxa=0;
        int maxb=0;
        for(int i=0;i<a;i++) {
            int x;
            scanf("%d ",&x);
            maxa=max(maxa,x);
        }
        scanf("\n");
        for(int i=0;i<b;i++) {
            int x;
            scanf("%d ",&x);
            maxb=max(maxb,x);
        }
        if (maxa>=maxb) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }
    return 0;
}