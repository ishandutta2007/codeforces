#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void solve(){
    ll n;
    scanf("%lld", &n);
    while(n!=1){
        if (n%2) break;
        n /= 2;
    }
    if (n!=1) printf("YES\n");
    else printf("NO\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}