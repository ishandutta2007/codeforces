#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        if (n==1){
            printf("-1\n");
            continue;
        }
        if (n==2){
            printf("43\n");
            continue;
        }
        if (n==3){
            printf("443\n");
            continue;
        }
        for (int i=1;i<=n-3;i++){
            if ((n-i)%2) printf("2");
            else printf("4");
        }
        printf("443\n");
    }
    return 0;
}