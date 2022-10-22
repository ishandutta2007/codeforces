#include <cstdio>
#include <algorithm>
 
using namespace std;
 
int main(void) {
    int a1,a2,k1,k2,n;
    scanf("%d\n%d\n%d\n%d\n%d", &a1, &a2, &k1, &k2, &n);
    int mini;
    int maxi;
    int x=a1*(k1-1)+a2*(k2-1);
    if (x>=n)
    mini=0;
    else
    mini=min(a1+a2,n-x);
    int minn;
    int maxn;
    int minp;
    int maxp;
    if (k1>=k2) {
        minn=k2;
        minp=a2;
        maxn=k1;
        maxp=a1;
    }
    else {
        minn=k1;
        maxn=k2;
        minp=a1;
        maxp=a2;
    }
    int p=n/minn;
    if (p<=minp) {
        maxi=p;
    }
    else {
        n-=minn*minp;
        maxi=minp;
        maxi+=min(n/maxn,maxp);
    }
    printf("%d %d", mini, maxi);
    return 0;
}