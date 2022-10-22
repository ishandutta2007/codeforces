#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int tc;
    scanf("%d\n",&tc);
    for(int t=0;t<tc;t++) {
        int n,m;
        scanf("%d %d",&n,&m);
        printf("%d\n",(n*m+1)/2);
    }
}