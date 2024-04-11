#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int tc;
    scanf("%d\n",&tc);
    for(int t=0;t<tc;t++) {
        int n,m;
        scanf("%d %d\n",&n,&m);
        if (n==1) {
            printf("0\n");
        }
        else if (n==2) {
            printf("%d\n",m);
        }
        else {
            printf("%d\n",m*2);
        }
    }
}