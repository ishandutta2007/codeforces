#include <cstdio>

int mypow(int a,int b) {
    if (b==0) {
        return 1;
    }
    return a*mypow(a,b-1);
}

int main(void) {
    int n,l,r;
    scanf("%d %d %d",&n,&l,&r);
    int minret=mypow(2,l)-1+n-l;
    long long maxret=mypow(2,r)-1;
    long long maxi=mypow(2,r-1);
    maxret+=maxi*(n-r);
    printf("%d %lld",minret,maxret);
    return 0;
}