#include <cstdio>
#include <algorithm>
using namespace std;

int main(void) {
    int k;
    scanf("%d\n", &k);
    for(int t=0;t<k;t++) {
        int a,b,c;
        scanf("%d %d %d\n", &a, &b, &c);
        int sum=0;
        while(b>=1&&c>=2) {
            b-=1;
            c-=2;
            sum+=3;
        }
        while(a>=1&&b>=2) {
            a-=1;
            b-=2;
            sum+=3;
        }
        printf("%d\n", sum);
    }
    return 0;
}