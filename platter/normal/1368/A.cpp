#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        int a,b,n;
        scanf("%d %d %d",&a,&b,&n);
        int ret=0;
        for(;a<=n&&b<=n;ret++) {
            if (a<b) {
                a+=b;
            }
            else {
                b+=a;
            }
        }
        printf("%d\n",ret);
    }
}