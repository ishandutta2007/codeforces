#include <cstdio>
#include <algorithm>
using namespace std;

int main(void) {
    int a,b,c,d,e,f;
    scanf("%d\n%d\n%d\n%d\n%d\n%d",&a,&b,&c,&d,&e,&f);
    int maxcost=0;
    int firstset=0;
    while (a>=0&&d>=0) {
        maxcost=max(maxcost,min(b,min(c,d))*f+e*firstset);
        a--;
        d--;
        firstset+=1;
    }
    printf("%d",maxcost);
    return 0;
}