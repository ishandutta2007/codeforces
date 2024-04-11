#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void solve(){
    int n;
    scanf("%d", &n);
    if (n==1) printf("9\n");
    else if (n==2) printf("98\n");
    else{
        printf("98");
        for (int i=2;i<n;i++){
            printf("%d", (i+7)%10);
        }
        printf("\n");
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