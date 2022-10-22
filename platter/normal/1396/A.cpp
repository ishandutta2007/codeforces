#include <bits/stdc++.h>
using namespace std;

long long arr[100000];
int n;

int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%lld",&arr[i]);
    }
    if (n==1) {
        printf("1 1\n0\n1 1\n0\n1 1\n%lld",-arr[0]);
        return 0;
    }
    printf("1 %d\n",n);
    for(int i=0;i<n;i++) {
        long long val=arr[i]%(n-1);
        val=-val;
        val%=n-1;
        val+=n-1;
        val%=n-1;
        printf("%lld ",n*val);
        arr[i]+=n*val;
    }
    printf("\n");
    printf("1 %d\n",n-1);
    for(int i=0;i<n-1;i++) {
        printf("%lld ",-arr[i]);
    }
    printf("\n");
    printf("%d %d\n",n,n);
    printf("%lld",-arr[n-1]);
    return 0;
}