#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void solve(){
    int n, k;
    scanf("%d %d", &n, &k);
    if (n==4){
        if (k==0) printf("0 3\n1 2\n");
        if (k==1) printf("0 2\n1 3\n");
        if (k==2) printf("0 1\n2 3\n");
        if (k==3) printf("-1\n");
        return;
    }

    if (k==0){
        for (int i=0;i<n/2;i++) printf("%d %d\n", i, n-1-i);
    }
    else if (k==n-1){
        printf("%d %d\n", n-1, n-2);
        printf("%d %d\n", 1, 3);
        printf("%d %d\n", 0, n-4);
        printf("%d %d\n", 2, n-3);

        for (int i=4;i<n/2;i++) printf("%d %d\n", i, n-1-i);
    }
    else{
        printf("%d %d\n", k, n-1);
        printf("%d %d\n", 0, n-1-k);
        for (int i=1;i<n/2;i++) if (i!=k && n-1-i!=k){
            printf("%d %d\n", i, n-1-i);
        }
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}