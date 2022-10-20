#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void solve(){
    int n;
    scanf("%d", &n);
    if (n==1){
        printf("FastestFinger\n");
        return;
    }
    if (n&1){
        printf("Ashishgup\n");
        return;
    }
    if (n==2){
        printf("Ashishgup\n");
        return;
    }
    if (__builtin_popcount(n)==1){
        printf("FastestFinger\n");
        return;
    }
    if ((n/2)%2==0){
        printf("Ashishgup\n");
        return;
    }
    n /= 2;
    int c=0;
    for (int i=3;i<100000;i++){
        while(n%i==0){
            c++;
            n /= i;
        }
    }
    if (n!=1) c++;
    if (c>=2){
        printf("Ashishgup\n");
    }
    else printf("FastestFinger\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}