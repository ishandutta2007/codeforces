#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int tc;
    scanf("%d\n",&tc);
    for(int t=0;t<tc;t++) {
        long long n;
        scanf("%lld\n",&n);
        long long ret=0;
        for(long long i=1;i<n;i+=2) {
            ret+=n*n-i*i;
        }
        printf("%lld\n",ret);
    }
}