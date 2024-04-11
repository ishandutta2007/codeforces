#include <bits/stdc++.h>
using namespace std;

long long getvalue(int l) {
    long long ret=1;
    for(int i=0;i<l%10;i++) {
        ret*=l/10+1;
    }
    for(int i=l%10;i<10;i++) {
        ret*=l/10;
    }
    return ret;
}

char str[11]="codeforces";

int main(void) {
    long long k;
    scanf("%lld",&k);
    for(int i=10;;i++) {
        if (getvalue(i)>=k) {
            for(int j=0;j<i%10;j++) {
                for(int k=0;k<=i/10;k++) {
                    printf("%c",str[j]);
                }
            }
            for(int j=i%10;j<10;j++) {
                for(int k=0;k<i/10;k++) {
                    printf("%c",str[j]);
                }
            }
            return 0;
        }
    }
}