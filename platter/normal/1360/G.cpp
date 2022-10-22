#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b) {
    if (b==0) {
        return a;
    }
    return gcd(b,a%b);
}

int main(void) {
    int tc;
    scanf("%d\n",&tc);
    for(int t=0;t<tc;t++) {
        int n,m,a,b;
        scanf("%d %d %d %d\n",&n,&m,&a,&b);
        if (a*n!=b*m) {
            printf("NO\n");
            continue;
        }
        printf("YES\n");
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if ((i*gcd(m,a)+j)%m<a) {
                    printf("1");
                }
                else {
                    printf("0");
                }
            }
            printf("\n");
        }
    }
}