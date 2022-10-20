#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void solve(){
    int n, k;
    scanf("%d %d", &n, &k);
    if (k==3){
        if (n==4){
            printf("1 1 2\n"); return;
        }
        int pw=1;
        while(n%2==0){
            pw *= 2;
            n /= 2;
        }
        if (n==1) printf("%d %d %d\n", pw/4, pw/4, pw/2);
        else printf("%d %d %d\n", pw, pw*(n/2), pw*(n/2));
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