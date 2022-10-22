#include <cstdio>
#include <algorithm>
using namespace std;

int now=0;
int a[10000];

int check(int n) {
    while(n>0) {
        if (n%3==2) {
            return 0;
        }
        n-=n%3;
        n/=3;
    }
    return 1;
}

void makearray() {
    for(int i=1;i<=20000;i++) {
        if (check(i)==1) {
            a[now]=i;
            now+=1;
        }
    }
}

int main(void) {
    makearray();
    int c;
    scanf("%d\n", &c);
    for(int t=0;t<c;t++) {
        int num;
        scanf("%d\n", &num);
        printf("%d\n", *lower_bound(a,a+now,num));
    }
    return 0;
}