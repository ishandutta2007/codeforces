#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int tc;
    scanf("%d\n",&tc);
    for(int t=0;t<tc;t++) {
        long long x1,y1,x2,y2;
        scanf("%lld %lld %lld %lld\n",&x1,&y1,&x2,&y2);
        long long pos1=x1+y1;
        long long pos2=x2+y2;
        long long p1=x1;
        long long p2=x2;
        long long ret=(max(pos2-pos1,pos1-pos2)+1-max(p1-p2,p2-p1))*max(p1-p2,p2-p1)-max(p2-p1,p1-p2);
        printf("%lld\n",ret+1);
    }
}