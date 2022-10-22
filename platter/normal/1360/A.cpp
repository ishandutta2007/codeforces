#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int tc;
    scanf("%d\n",&tc);
    for(int t=0;t<tc;t++) {
        int a,b;
        scanf("%d %d\n",&a,&b);
        int x=min(max(a,b*2),max(a*2,b));
        printf("%d\n",x*x);
    }
}