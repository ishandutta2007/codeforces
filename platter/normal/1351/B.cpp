#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int tc;
    scanf("%d\n",&tc);
    for(int t=0;t<tc;t++) {
        int a,b,c,d;
        scanf("%d %d\n%d %d\n",&a,&b,&c,&d);
        if ((a==c&&b+d==c)||(a==d&&b+c==d)||(b==c&&a+d==b)||(b==d&&a+c==b)) {
            printf("Yes\n");
        }
        else {
            printf("No\n");
        }
    }
}