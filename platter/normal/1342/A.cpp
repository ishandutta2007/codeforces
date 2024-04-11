#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int tc;
    scanf("%d\n",&tc);
    for(int t=0;t<tc;t++) {
        long long a,b;
        long long x,y;
        scanf("%lld %lld\n%lld %lld\n",&x,&y,&a,&b);
        long long one=a*(x+y);
        long long two=b*min(x,y)+a*(max(x,y)-min(x,y));
        printf("%lld\n",min(one,two));
    }
}