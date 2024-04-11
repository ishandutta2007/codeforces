#include <bits/stdc++.h>
using namespace std;

char str[101];

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
        int a,b,q;
        scanf("%d %d %d\n",&a,&b,&q);
        int st=(a*b)/gcd(a,b);
        for(int i=0;i<q;i++) {
            long long l,r;
            scanf("%lld %lld\n",&l,&r);
            long long sl=l;
            long long sr=r;
            long long ret=0;
            if (l/st==r/st) {
                if (l%st<max(a,b)&&r%st<max(a,b)) {
                    ret=r-l+1;
                }
                else if (l%st<max(a,b)) {
                    ret=max(a,b)-l%st;
                }
                else {
                    ret=0;
                }
                printf("%lld ",sr-sl+1-ret);
                continue;
            }
            if (l%st<max(a,b))
                ret+=max(a,b)-l%st;
            l=(l/st+1)*st;
            ret+=min(r%st+1,(long long)max(a,b));
            r=(r/st)*st-1;
            ret+=((r-l+1)/st)*(long long)max(a,b);
            printf("%lld ",sr-sl+1-ret);
        }
        printf("\n");
    }
}