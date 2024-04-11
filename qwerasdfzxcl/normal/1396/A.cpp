#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
ll a[100100];

int main(){
    int n;
    scanf("%d", &n);
    for (int i=0;i<n;i++) scanf("%lld", a+i);
    if (n==1){
        printf("1 1\n");
        printf("%lld\n", -a[0]);
        printf("1 1\n");
        printf("0\n");
        printf("1 1\n");
        printf("0\n");
        return 0;
    }
    printf("1 %d\n", n);
    for (int i=0;i<n-1;i++){
        ll k = n-(a[i]%n);
        ll x = (n-1)*k;
        printf("%lld ", x-a[i]);
        a[i] = x;
    }
    printf("0\n");
    printf("%d %d\n", n, n);
    printf("%lld\n", -a[n-1]);
    printf("1 %d\n", n-1);
    for (int i=0;i<n-1;i++){
        printf("%lld ", -a[i]);
    }
    printf("\n");
    return 0;
}