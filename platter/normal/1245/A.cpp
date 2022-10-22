#include <cstdio>
#include <algorithm>
using namespace std;

int gc(int a, int b) {
    if (b==0)
    return a;
    return gc(b,a%b);
}

int main(void) {
    int c;
    scanf("%d\n", &c);
    for(int t=0;t<c;t++) {
        int a,b;
        scanf("%d %d\n", &a, &b);
        if (gc(a,b)==1)
        printf("Finite\n");
        else
        printf("Infinite\n");
    }
    return 0;
}