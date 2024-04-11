#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void solve(){
    int n;
    scanf("%d", &n);
    if (n==1){
        printf("Bob\n"); return;
    }
    int k = 0;
    while(n%2==0){
        n>>=1; k++;
    }
    if (n==1){
        if (k&1) printf("Bob\n");
        else printf("Alice\n");
    }
    else{
        if (k) printf("Alice\n");
        else printf("Bob\n");
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