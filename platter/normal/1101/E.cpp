#include <cstdio>
#include <algorithm>
using namespace std;

int main(void) {
    int n;
    scanf("%d\n",&n);
    int both=0;
    int one=0;
    for(int i=0;i<n;i++) {
        char x;
        int a,b;
        scanf("%c %d %d\n",&x,&a,&b);
        int small=min(a,b);
        int big=max(a,b);
        if (x=='+') {
            both=max(both,small);
            one=max(one,big);
        }
        if (x=='?') {
            if (small>=both&&big>=one) {
                printf("YES\n");
            }
            else {
                printf("NO\n");
            }
        }
    }
    return 0;
}