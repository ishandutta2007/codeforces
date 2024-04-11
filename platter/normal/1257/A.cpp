#include <cstdio>
#include <algorithm>
using namespace std;

int main(void) {
    int c;
    scanf("%d\n", &c);
    for(int t=0;t<c;t++) {
        int n,x,a,b;
        scanf("%d %d %d %d\n", &n, &x, &a, &b);
        int num=a-b;
        if (num<0)
        num=-num;
        printf("%d\n",min(num+x,n-1));
    }
    return 0;
}