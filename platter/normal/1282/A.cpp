#include <cstdio>
#include <algorithm>
using namespace std;

int main(void) {
    int c;
    scanf("%d\n",&c);
    for(int t=0;t<c;t++) {
        int a,b,c,r;
        scanf("%d %d %d %d\n",&a,&b,&c,&r);
        int small=min(a,b);
        int big=max(a,b);
        int s=c-r;
        int e=c+r;
        int line=min(big,e)-max(small,s);
        if (line<0) {
            line=0;
        }
        printf("%d\n",big-small-line);
    }
    return 0;
}