#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void solve(){
    int n;
    scanf("%d", &n);
    if (n%2==1){
        int i;
        for (i=1;i<=n/2+1;i++){
            int j;
            for (j=i+1;j<=i+n/2;j++) printf("1 ");
            for (;j<=n;j++) printf("-1 ");
        }
        for (;i<=n-1;i++){
            int j;
            for (j=i+1;j<=n;j++) printf("1 ");
        }
        printf("\n");
        return;
    }
    int i;
    for (i=1;i<=n-1;i++){
        int j;
        for (j=i+1;j<=i+n/2-1;j++) if (j<=n) printf("1 ");
        if (j<=n) printf("0 ");
        for (j=i+n/2+1;j<=n;j++) printf("-1 ");
    }
    printf("\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}