#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void solve(){
    ll n, k;
    scanf("%lld %lld", &n, &k);
    if (n%2==0){
        printf("%lld\n", (k-1)%n+1);
        return;
    }
    k %= n*(n/2);
    if (k==0) k=n*(n/2);
    ll tmp=n/2;
    printf("%lld\n", ((k-1)%n+(k-1)/tmp)%n+1);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}