#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        ll n, m, r, c;
        scanf("%lld %lld %lld %lld", &n, &m, &r, &c);
        ll ans=max(r-1, n-r)+max(c-1, m-c);
        printf("%lld\n", ans);
    }
    return 0;
}