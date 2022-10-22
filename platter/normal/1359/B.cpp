#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int tc;
    scanf("%d\n",&tc);
    for(int t=0;t<tc;t++) {
        int n,m,x,y;
        scanf("%d %d %d %d\n",&n,&m,&x,&y);
        int one=0;
        int two=0;
        int ret=0;
        for(int i=0;i<n;i++) {
            int len=0;
            for(int j=0;j<m;j++) {
                char x;
                scanf("%c",&x);
                if (x=='*') {
                    one+=len%2;
                    two+=len/2;
                    len=0;
                }
                else {
                    len++;
                }
            }
            one+=len%2;
            two+=len/2;
            scanf("\n");
        }
        printf("%d\n",min((two*2+one)*x,one*x+two*y));
    }
}