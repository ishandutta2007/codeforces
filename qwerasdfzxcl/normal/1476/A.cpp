#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void solve(){
    int n, k;
    scanf("%d %d", &n, &k);
    if (n>k){
        if (n%k==0) printf("1\n");
        else printf("2\n");
        return;
    }
    if (k%n==0) printf("%d\n", k/n);
    else printf("%d\n", k/n+1);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}