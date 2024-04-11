#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void solve(){
    ll p, a, b, c;
    scanf("%lld %lld %lld %lld", &p, &a, &b, &c);
    ll val1=(a-p%a)%a, val2=(b-p%b)%b, val3=(c-p%c)%c;
    printf("%lld\n", min(min(val1, val2), val3));
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}