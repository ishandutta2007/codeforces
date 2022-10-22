#include <cstdio>
#include <algorithm>
using namespace std;

int main(void) {
    int c;
    scanf("%d\n", &c);
    for(int t=0;t<c;t++) {
        int r,g,b;
        scanf("%d %d %d\n", &r, &g, &b);
        printf("%d\n",min(min((r+g+b)/2,r+g),min(g+b,b+r)));
    }
    return 0;
}