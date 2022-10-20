#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void solve(){
    ll x, y;
    scanf("%lld %lld", &x, &y);
    if (x==y){printf("0 0\n"); return;}
    if (x>y) swap(x, y);
    ll d = y-x;
    x %= d;
    printf("%lld %lld\n", d, min(x, d-x));
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}