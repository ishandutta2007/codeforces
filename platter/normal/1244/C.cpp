#include <stdio.h>
#include <iostream>
using namespace std;
 
long long gcd(long long a, long long b) {
    if (b==0)
    return a;
    return gcd(b,a%b);
}
 
int main(void) {
    long long n,p;
    long long w,d;
    cin >> n >> p >> w >> d;
    long long divide=gcd(w,d);
    if (p%divide!=0) {
        printf("-1");
        return 0;
    }
    p=p/divide;
    w=w/divide;
    d=d/divide;
    long long key;
    for(long long i=0;i<w;i++) {
        if (p%w==(i*d)%w) {
            key=i;
            break;
        }
        if (i==w-1) {
        	printf("-1");
        	return 0;
        }
    }
    long long draw=key;
    long long win=(p-draw*d)/w;
    long long lose=n-win-draw;
        if (win<0) {
            printf("-1");
        }
        else if (lose>=0) {
            printf("%lld %lld %lld", win, draw, lose);
        }
        if (lose<0)
        printf("-1");
    return 0;
}